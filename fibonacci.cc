#include <node_api.h>

napi_value Sum (napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  napi_value argv[1];
  int times = 0;
  unsigned long long int sum = 0;

  status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to parse arguments");
  }

  status = napi_get_value_int32(env, argv[0], &times);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Invalid number was passed as argument");
  }

  napi_value result;

  for (int i = 0; i < times; i++) {
    sum = sum + i;
  }

  status = napi_create_int64(env, sum, &result);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to create return value");
  }

  return result;
}

napi_value Fibonacci (napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  napi_value argv[1];
  int times = 0;
  unsigned long long int nowNum = 0;
  unsigned long long int lastNum = 1;
  unsigned long long int lastLastNum = 0;

  status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to parse arguments");
  }

  status = napi_get_value_int32(env, argv[0], &times);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Invalid number was passed as argument");
  }

  napi_value result;

  for (int i = 1; i < times; i++) {
    nowNum = lastNum + lastLastNum;
    lastLastNum = lastNum;
    lastNum = nowNum;
  }

  status = napi_create_int64(env, nowNum, &result);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to create return value");
  }

  return result;
}

napi_value Init (napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc[] = {
    {"calculate", NULL, Fibonacci, NULL, NULL, NULL, napi_default, NULL},
    {"sum", NULL, Sum, NULL, NULL, NULL, napi_default, NULL}
  };
  status = napi_define_properties(env, exports, 2, desc);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to wrap native function");
  }

  return exports;
}

NAPI_MODULE(fibonacci, Init);
