#include "swisseph.h"

Napi::Object init(Napi::Env env, Napi::Object exports) {

  /**
   * DATE
   */
	exports.Set(Napi::String::New(env, "node_swe_date_conversion"), Napi::Function::New(env, node_swe_date_conversion));
  exports.Set(Napi::String::New(env, "node_swe_julday"), Napi::Function::New(env, node_swe_julday));
  exports.Set(Napi::String::New(env, "node_swe_revjul"), Napi::Function::New(env, node_swe_revjul));
  exports.Set(Napi::String::New(env, "node_swe_utc_to_jd"), Napi::Function::New(env, node_swe_utc_to_jd));
  exports.Set(Napi::String::New(env, "node_swe_jdet_to_utc"), Napi::Function::New(env, node_swe_jdet_to_utc));
  exports.Set(Napi::String::New(env, "node_swe_jdut1_to_utc"), Napi::Function::New(env, node_swe_jdut1_to_utc));
  exports.Set(Napi::String::New(env, "node_swe_utc_time_zone"), Napi::Function::New(env, node_swe_utc_time_zone));


	/**
   * ECLIPSE
   */


  /**
   * HEL
   */


  /**
   * HOUSE
   */


  /**
   * POS
   */


  /**
   * UTIL
   */


  return exports;
}

NODE_API_MODULE(swisseph, init);