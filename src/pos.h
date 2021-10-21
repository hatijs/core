#ifndef __swisseph_pos_h__
#define __swisseph_pos_h__

/**
 * char swe_version(char *)
 * =>
 * node_swe_version: () => string
 */
Napi::String node_swe_version(const Napi::CallbackInfo& info);

/**
 * int32 swe_calc(double tjd, int ipl, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_calc: (tjd: number, ipl: number, iflag: number) => {
 *   longitude:      | rectAscension:      | x:  number,
 *   latitude:       | declination:        | y:  number,
 *   distance:       | distance:           | z:  number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *   latitudeSpeed:  | declinationSpeed:   | dy: number,
 *   distanceSpeed:  | distanceSpeed:      | dz: number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_calc(const Napi::CallbackInfo& info);

/**
 * int32 swe_calc_ut(double tjd_ut, int32 ipl, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_calc_ut: (tjd_ut: number, ipl: number, iflag: number) => {
 *   longitude:      | rectAscension:      | x:  number,
 *   latitude:       | declination:        | y:  number,
 *   distance:       | distance:           | z:  number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *   latitudeSpeed:  | declinationSpeed:   | dy: number,
 *   distanceSpeed:  | distanceSpeed:      | dz: number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_calc_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_fixstar: (star: string, tjd: number, iflag: number) => {
 *   name:																				string,
 *   longitude:      | rectAscension:      | x:		number,
 *   latitude:       | declination:        | y:		number,
 *   distance:       | distance:           | z:		number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx:	number,
 *   latitudeSpeed:  | declinationSpeed:   | dy:	number,
 *   distanceSpeed:  | distanceSpeed:      | dz:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_fixstar_ut: (star: string, tjd_ut: number, iflag: number) => {
 *   name:																				string,
 *   longitude:      | rectAscension:      | x:		number,
 *   latitude:       | declination:        | y:		number,
 *   distance:       | distance:           | z:		number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx:	number,
 *   latitudeSpeed:  | declinationSpeed:   | dy:	number,
 *   distanceSpeed:  | distanceSpeed:      | dz:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar_mag(char *star, double *mag, char *serr)
 * =>
 * node_swe_fixstar_mag: (star: string) => {
 *   name:			string,
 *   magnitude:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar_mag(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar2(char *star, double tjd, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_fixstar2: (string star, double tjd, int32 iflag) => {
 *   name:																				string,
 *   longitude:      | rectAscension:      | x:		number,
 *   latitude:       | declination:        | y:		number,
 *   distance:       | distance:           | z:		number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx:	number,
 *   latitudeSpeed:  | declinationSpeed:   | dy:	number,
 *   distanceSpeed:  | distanceSpeed:      | dz:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar2(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar2_ut(char *star, double tjd_ut, int32 iflag, double *xx, char *serr)
 * =>
 * node_swe_fixstar2_ut: (star: string, tjd_ut: number, iflag: number) => {
 *   name:																				string,
 *   longitude:      | rectAscension:      | x:		number,
 *   latitude:       | declination:        | y:		number,
 *   distance:       | distance:           | z: 	number,
 *   longitudeSpeed: | rectAscensionSpeed: | dx:	number,
 *   latitudeSpeed:  | declinationSpeed:   | dy:	number,
 *   distanceSpeed:  | distanceSpeed:      | dz:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar2_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_fixstar2_mag(char *star, double *mag, char *serr)
 * =>
 * node_swe_fixstar2_mag: (star: string) => {
 *   name: 			string,
 *   magnitude:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_fixstar2_mag(const Napi::CallbackInfo& info);

/**
 * void swe_close(void)
 * =>
 * node_swe_close: () => {}
 */
Napi::Object node_swe_close(const Napi::CallbackInfo& info);

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * node_swe_set_ephe_path: (path: string) => string
 */
Napi::String node_swe_set_ephe_path(const Napi::CallbackInfo& info);

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * node_swe_set_jpl_file: (fname: string) => string
 */
Napi::String node_swe_set_jpl_file(const Napi::CallbackInfo& info);

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * node_swe_get_planet_name: (ipl: number) => string
 */
Napi::String node_swe_get_planet_name(const Napi::CallbackInfo& info);

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * node_swe_set_topo: (geolon: number, geolat: number, geoalt: number) => {}
 */
Napi::Object node_swe_set_topo(const Napi::CallbackInfo& info);

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * node_swe_set_sid_mode: (sid_mode: number, t0: number, ayan_t0: number) => {}
 */
Napi::Object node_swe_set_sid_mode(const Napi::CallbackInfo& info);

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * node_swe_get_ayanamsa: (tjd_et: number) => number
 */
Napi::Number node_swe_get_ayanamsa(const Napi::CallbackInfo& info);

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * node_swe_get_ayanamsa_ut: (tjd_ut: number) => number
 */
Napi::Number node_swe_get_ayanamsa_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_get_ayanamsa_ex(double tjd_et, int32 iflag, double *daya, char *serr)
 * =>
 * node_swe_get_ayanamsa_ex: (tjd_et: number, iflag: number) => {
 *   ayanamsa:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_get_ayanamsa_ex(const Napi::CallbackInfo& info);

/**
 * int32 swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag, double *daya, char *serr)
 * =>
 * node_swe_get_ayanamsa_ex_ut: (tjd_ut: number, iflag: number) => {
 *   ayanamsa:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_get_ayanamsa_ex_ut(const Napi::CallbackInfo& info);

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * node_swe_get_ayanamsa_name: (isidmode: number) => string
 */
Napi::String node_swe_get_ayanamsa_name(const Napi::CallbackInfo& info);

/**
 * int32 swe_nod_aps(double tjd_et, int32 ipl, int32 iflag, int32  method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 * =>
 * node_swe_nod_aps: (tjd_et: number, ipl: number, iflag: number, method: number) => {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   }
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_nod_aps(const Napi::CallbackInfo& info);

/**
 * int32 swe_nod_aps_ut(double tjd_ut, int32 ipl, int32 iflag, int32 method, double *xnasc, double *xndsc, double *xperi, double *xaphe, char *serr)
 * =>
 * node_swe_nod_aps_ut: (tjd_ut: number, ipl: number, iflag: number, method: number) => {
 *   ascending: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   descending: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   perihelion: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   },
 *   aphelion: {
 *     longitude:      | rectAscension:      | x:  number,
 *     latitude:       | declination:        | y:  number,
 *     distance:       | distance:           | z:  number,
 *     longitudeSpeed: | rectAscensionSpeed: | dx: number,
 *     latitudeSpeed:  | declinationSpeed:   | dy: number,
 *     distanceSpeed:  | distanceSpeed:      | dz: number
 *   }
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_nod_aps_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_get_orbital_elements(double tjd_et, int32 ipl, in32 iflag, double *dret, char *serr)
 * =>
 * node_swe_get_orbital_elements: (tjd_et: number, ipl: number, iflag: number) => {
 *   aphelionDistance:		number,
 *   ascendingNode:				number,
 *   eccentricAnomaly:		number,
 *   eccentricity:				number,
 *   inclination:					number,
 *   meanAnomaly:					number,
 *   meanDailyMotion:			number,
 *   meanLongitude:				number,
 *   periapsis:						number,
 *   periapsisArg:				number,
 *   perihelionDistance:	number,
 *   perihelionPassage:		number,
 *   semimajorAxis:				number,
 *   siderealPeriod:			number,
 *   synodicPeriod:				number,
 *   tropicalPeriod:			number,
 *   trueAnomaly:					number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_get_orbital_elements(const Napi::CallbackInfo& info);

/**
 * int32 swe_orbit_max_min_true_distance(double tjd_et, int32 ipl, int32 iflag, double *dmax, double *dmin, double *dtrue, char *serr)
 * =>
 * node_swe_orbit_max_min_true_distance: (tjd_et: number, ipl: number, iflag: number) => {
 *   maxDistance:		number,
 *   minDistance:		number,
 *   trueDistance:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_orbit_max_min_true_distance(const Napi::CallbackInfo& info);

#endif