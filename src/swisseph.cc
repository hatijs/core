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
	exports.Set(Napi::String::New(env, "node_swe_gauquelin_sector"), Napi::Function::New(env, node_swe_gauquelin_sector));
	exports.Set(Napi::String::New(env, "node_swe_sol_eclipse_where"), Napi::Function::New(env, node_swe_sol_eclipse_where));
	exports.Set(Napi::String::New(env, "node_swe_lun_occult_where"), Napi::Function::New(env, node_swe_lun_occult_where));
	exports.Set(Napi::String::New(env, "node_swe_sol_eclipse_how"), Napi::Function::New(env, node_swe_sol_eclipse_how));
	exports.Set(Napi::String::New(env, "node_swe_sol_eclipse_when_loc"), Napi::Function::New(env, node_swe_sol_eclipse_when_loc));
	exports.Set(Napi::String::New(env, "node_swe_lun_occult_when_loc"), Napi::Function::New(env, node_swe_lun_occult_when_loc));
	exports.Set(Napi::String::New(env, "node_swe_sol_eclipse_when_glob"), Napi::Function::New(env, node_swe_sol_eclipse_when_glob));
	exports.Set(Napi::String::New(env, "node_swe_lun_occult_when_glob"), Napi::Function::New(env, node_swe_lun_occult_when_glob));
	exports.Set(Napi::String::New(env, "node_swe_lun_eclipse_how"), Napi::Function::New(env, node_swe_lun_eclipse_how));
	exports.Set(Napi::String::New(env, "node_swe_lun_eclipse_when"), Napi::Function::New(env, node_swe_lun_eclipse_when));
	exports.Set(Napi::String::New(env, "node_swe_lun_eclipse_when_loc"), Napi::Function::New(env, node_swe_lun_eclipse_when_loc));
	exports.Set(Napi::String::New(env, "node_swe_pheno"), Napi::Function::New(env, node_swe_pheno));
	exports.Set(Napi::String::New(env, "node_swe_pheno_ut"), Napi::Function::New(env, node_swe_pheno_ut));
	exports.Set(Napi::String::New(env, "node_swe_refrac"), Napi::Function::New(env, node_swe_refrac));
	exports.Set(Napi::String::New(env, "node_swe_refrac_extended"), Napi::Function::New(env, node_swe_refrac_extended));
	exports.Set(Napi::String::New(env, "node_swe_set_lapse_rate"), Napi::Function::New(env, node_swe_set_lapse_rate));
	exports.Set(Napi::String::New(env, "node_swe_azalt"), Napi::Function::New(env, node_swe_azalt));
	exports.Set(Napi::String::New(env, "node_swe_azalt_rev"), Napi::Function::New(env, node_swe_azalt_rev));
	exports.Set(Napi::String::New(env, "node_swe_rise_trans"), Napi::Function::New(env, node_swe_rise_trans));
	exports.Set(Napi::String::New(env, "node_swe_rise_trans_true_hor"), Napi::Function::New(env, node_swe_rise_trans_true_hor));


  /**
   * HEL
   */
	exports.Set(Napi::String::New(env, "node_swe_heliacal_ut"), Napi::Function::New(env, node_swe_heliacal_ut));
	exports.Set(Napi::String::New(env, "node_swe_heliacal_pheno_ut"), Napi::Function::New(env, node_swe_heliacal_pheno_ut));
	exports.Set(Napi::String::New(env, "node_swe_vis_limit_mag"), Napi::Function::New(env, node_swe_vis_limit_mag));


  /**
   * HOUSE
   */
	exports.Set(Napi::String::New(env, "node_swe_date_conversion"), Napi::Function::New(env, node_swe_date_conversion));
	exports.Set(Napi::String::New(env, "node_swe_julday"), Napi::Function::New(env, node_swe_julday));
	exports.Set(Napi::String::New(env, "node_swe_revjul"), Napi::Function::New(env, node_swe_revjul));
	exports.Set(Napi::String::New(env, "node_swe_utc_to_jd"), Napi::Function::New(env, node_swe_utc_to_jd));
	exports.Set(Napi::String::New(env, "node_swe_jdet_to_utc"), Napi::Function::New(env, node_swe_jdet_to_utc));
	exports.Set(Napi::String::New(env, "node_swe_jdut1_to_utc"), Napi::Function::New(env, node_swe_jdut1_to_utc));
	exports.Set(Napi::String::New(env, "node_swe_utc_time_zone"), Napi::Function::New(env, node_swe_utc_time_zone));


  /**
   * POS
   */


  /**
   * UTIL
   */


  return exports;
}

NODE_API_MODULE(swisseph, init);