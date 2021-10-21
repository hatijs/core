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
	exports.Set(Napi::String::New(env, "node_swe_version"), Napi::Function::New(env, node_swe_version));
	exports.Set(Napi::String::New(env, "node_swe_calc"), Napi::Function::New(env, node_swe_calc));
	exports.Set(Napi::String::New(env, "node_swe_calc_ut"), Napi::Function::New(env, node_swe_calc_ut));
	exports.Set(Napi::String::New(env, "node_swe_fixstar"), Napi::Function::New(env, node_swe_fixstar));
	exports.Set(Napi::String::New(env, "node_swe_fixstar_ut"), Napi::Function::New(env, node_swe_fixstar_ut));
	exports.Set(Napi::String::New(env, "node_swe_fixstar_mag"), Napi::Function::New(env, node_swe_fixstar_mag));
	exports.Set(Napi::String::New(env, "node_swe_fixstar2"), Napi::Function::New(env, node_swe_fixstar2));
	exports.Set(Napi::String::New(env, "node_swe_fixstar2_ut"), Napi::Function::New(env, node_swe_fixstar2_ut));
	exports.Set(Napi::String::New(env, "node_swe_fixstar2_mag"), Napi::Function::New(env, node_swe_fixstar2_mag));
	exports.Set(Napi::String::New(env, "node_swe_close"), Napi::Function::New(env, node_swe_close));
	exports.Set(Napi::String::New(env, "node_swe_set_ephe_path"), Napi::Function::New(env, node_swe_set_ephe_path));
	exports.Set(Napi::String::New(env, "node_swe_set_jpl_file"), Napi::Function::New(env, node_swe_set_jpl_file));
	exports.Set(Napi::String::New(env, "node_swe_get_planet_name"), Napi::Function::New(env, node_swe_get_planet_name));
	exports.Set(Napi::String::New(env, "node_swe_set_topo"), Napi::Function::New(env, node_swe_set_topo));
	exports.Set(Napi::String::New(env, "node_swe_set_sid_mode"), Napi::Function::New(env, node_swe_set_sid_mode));
	exports.Set(Napi::String::New(env, "node_swe_get_ayanamsa"), Napi::Function::New(env, node_swe_get_ayanamsa));
	exports.Set(Napi::String::New(env, "node_swe_get_ayanamsa_ut"), Napi::Function::New(env, node_swe_get_ayanamsa_ut));
	exports.Set(Napi::String::New(env, "node_swe_get_ayanamsa_ex"), Napi::Function::New(env, node_swe_get_ayanamsa_ex));
	exports.Set(Napi::String::New(env, "node_swe_get_ayanamsa_ex_ut"), Napi::Function::New(env, node_swe_get_ayanamsa_ex_ut));
	exports.Set(Napi::String::New(env, "node_swe_get_ayanamsa_name"), Napi::Function::New(env, node_swe_get_ayanamsa_name));
	exports.Set(Napi::String::New(env, "node_swe_nod_aps"), Napi::Function::New(env, node_swe_nod_aps));
	exports.Set(Napi::String::New(env, "node_swe_nod_aps_ut"), Napi::Function::New(env, node_swe_nod_aps_ut));
	exports.Set(Napi::String::New(env, "node_swe_get_orbital_elements"), Napi::Function::New(env, node_swe_get_orbital_elements));
	exports.Set(Napi::String::New(env, "node_swe_orbit_max_min_true_distance"), Napi::Function::New(env, node_swe_orbit_max_min_true_distance));

  /**
   * UTIL
   */


  return exports;
}

NODE_API_MODULE(swisseph, init);