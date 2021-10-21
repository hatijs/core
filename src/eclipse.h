#ifndef __swisseph_eclipse_h__
#define __swisseph_eclipse_h__

/**
 * int32 swe_gauquelin_sector(double t_ut, int32 ipl, char *starname, int32 iflag, int32 imeth, double *geopos, double atpress, double attemp, double *dgsect, char *serr)
 * =>
 * node_swe_gauquelin_sector: (t_ut: number, ipl: number, starname: string, iflag: number, imeth: number, longitude: number, latitude: number, height: number, atpress: number, attemp: number) => {
 *   name:						string,
 *   gauquelinSector:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_gauquelin_sector(const Napi::CallbackInfo& info);

/**
 * int32 swe_sol_eclipse_where(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * node_swe_sol_eclipse_where: (tjd_ut: number, ifl: number) => {
 *   longitude:									number,
 *   latitude:									number,
 *   solarDiameterFraction:			number,
 *   lonarToSolarDiameterRatio:	number,
 *   solarDiscFraction:					number,
 *   coreShadow:								number,
 *   azimuth:										number,
 *   trueAltitude:							number,
 *   apparentAltitude:					number,
 *   moonToSunAngularDistance:	number,
 *   eclipseMagnitude:					number,
 *   sarosNumber:								number,
 *   sarosMember:								number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_sol_eclipse_where(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_occult_where(double tjd_ut, int32 ipl, char *starname, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * node_swe_lun_occult_where: (tjd_ut: number, ipl: number, starname: string, ifl: number) => {
 *   longitude:									number,
 *   latitude:									number,
 *   solarDiameterFraction:			number,
 *   lonarToSolarDiameterRatio:	number,
 *   solarDiscFraction:					number,
 *   coreShadow:								number,
 *   azimuth:										number,
 *   trueAltitude:							number,
 *   apparentAltitude:					number,
 *   moonToSunAngularDistance:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_occult_where(const Napi::CallbackInfo& info);

/**
 * int32 swe_sol_eclipse_how(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * node_swe_sol_eclipse_how: (tjd_ut: number, ifl: number, longitude: number, latitude: number, height: number) => {
 *   solarDiameterFraction:			number,
 *   lonarToSolarDiameterRatio:	number,
 *   solarDiscFraction:					number,
 *   coreShadow:								number,
 *   azimuth:										number,
 *   trueAltitude:							number,
 *   apparentAltitude:					number,
 *   moonToSunAngularDistance:	number,
 *   eclipseMagnitude:					number,
 *   sarosNumber:								number,
 *   sarosMember:								number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_sol_eclipse_how(const Napi::CallbackInfo& info);

/**
 * int32 swe_sol_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 * =>
 * node_swe_sol_eclipse_when_loc: (tjd_start: number, ifl: number, longitude: number, latitude: number, height: number, backward: number) => {
 *   maximum:										number,
 *   first:											number,
 *   second:										number,
 *   third:											number,
 *   forth:											number,
 *   solarDiameterFraction:			number,
 *   lonarToSolarDiameterRatio:	number,
 *   solarDiscFraction:					number,
 *   coreShadow:								number,
 *   azimuth:										number,
 *   trueAltitude:							number,
 *   apparentAltitude:					number,
 *   moonToSunAngularDistance:	number,
 *   eclipseMagnitude:					number,
 *   sarosNumber:								number,
 *   sarosMember:								number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_sol_eclipse_when_loc(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_occult_when_loc(double tjd_start, int32 ipl, char *starname, int32 ifl, double *geopos, double *tret, double *attr, int32 backward, char *serr)
 * =>
 * node_swe_lun_occult_when_loc: (tjd_start: number, ipl: number, starname: string, ifl: number, longitude: number, latitude: number, height: number, backward: number) => {
 *   name:											string,
 *   maximum:										number,
 *   first:											number,
 *   second:										number,
 *   third:											number,
 *   forth:											number,
 *   solarDiameterFraction:			number,
 *   lonarToSolarDiameterRatio:	number,
 *   solarDiscFraction:					number,
 *   coreShadow:								number,
 *   azimuth:										number,
 *   trueAltitude:							number,
 *   apparentAltitude:					number,
 *   moonToSunAngularDistance:	number,
 *   eclipseMagnitude:					number,
 *   sarosNumber:								number,
 *   sarosMember:								number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_occult_when_loc(const Napi::CallbackInfo& info);

/**
 * int32 swe_sol_eclipse_when_glob(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * node_swe_sol_eclipse_when_glob: (tjd_start: number, ifl: number, ifltype: number, backward: number) => {
 *   maximum:			number,
 *   noon:				number,
 *   begin:				number,
 *   end:					number,
 *   totalBegin:	number,
 *   totalEnd:		number,
 *   centerBegin:	number,
 *   centerEnd:		number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_sol_eclipse_when_glob(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_occult_when_glob(double tjd_start, int32 ipl, char *starname, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * node_swe_lun_occult_when_glob(tjd_start: number, ipl: number, starname: string, ifl: number, ifltype: number, backward: number) => {
 *   name:				string,
 *   maximum:			number,
 *   noon:				number,
 *   begin:				number,
 *   end:					number,
 *   totalBegin: 	number,
 *   totalEnd:		number,
 *   centerBegin:	number,
 *   centerEnd:		number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_occult_when_glob(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_eclipse_how(double tjd_ut, int32 ifl, double *geopos, double *attr, char *serr)
 * =>
 * node_swe_lun_eclipse_how: (tjd_ut: number, ifl: number, longitude: number, latitude: number, height: number) => {
 *   umbralMagnitude:					number,
 *   penumbralMagnitude:			number,
 *   azimuth:									number,
 *   trueAltitude:						number,
 *   apparentAltitude:				number,
 *   oppositeDegreeDistance:	number,
 *   magnitude:								number,
 *   sarosNumber:							number,
 *   sarosMember:							number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_eclipse_how(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_eclipse_when(double tjd_start, int32 ifl, int32 ifltype, double *tret, int32 backward, char *serr)
 * =>
 * node_swe_lun_eclipse_when: (tjd_start: number, ifl: number, ifltype: number, backward: number) => {
 *   maximum:					number,
 *   partialBegin:		number,
 *   partialEnd:			number,
 *   totalBegin:			number,
 *   totalEnd:				number,
 *   penumbralBegin:	number,
 *   penumbralEnd:		number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_eclipse_when(const Napi::CallbackInfo& info);

/**
 * int32 swe_lun_eclipse_when_loc(double tjd_start, int32 ifl, double *geopos (in[3]), double *tret (out[10]), double *attr (out[20]), int32 backward, char *serr (out[AS_MAXCH]))
 * =>
 * node_swe_lun_eclipse_when_loc: (tjd_start: number, ifl: number, longitude: number, latitude: number, height: number, backward: number) => {
 *   maximum:											number,
 *   partialBegin:								number,
 *   partialEnd:									number,
 *   totalBegin:									number,
 *   totalEnd:										number,
 *   penumbralBegin:							number,
 *   penumbralEnd:								number,
 *   moonRise:										number,
 *   moonSet:											number,
 *   umbralMagnitude:							number,
 *   penumbralMagnitude:					number,
 *   azimuth:											number,
 *   trueAltitude:								number,
 *   apparentAltitude:						number,
 *   moonDistanceFromOpposition:	number,
 *   sarosNumber:									number,
 *   sarosMember:									number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_lun_eclipse_when_loc(const Napi::CallbackInfo& info);

/**
 * int32 swe_pheno(double tjd, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * node_swe_pheno: (tjd: number, ipl: number, iflag: number) => {
 *   phaseAngle:				number,
 *   phase:							number,
 *   elongation:				number,
 *   apparentDiameter:	number,
 *   apparentMagnitude:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_pheno(const Napi::CallbackInfo& info);

/**
 * int32 swe_pheno_ut(double tjd_ut, int32 ipl, int32 iflag, double *attr, char *serr)
 * =>
 * node_swe_pheno_ut: (tjd_ut: number, ipl: number, iflag: number) => {
 *   phaseAngle:				number,
 *   phase:							number,
 *   elongation:				number,
 *   apparentDiameter:	number,
 *   apparentMagnitude:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_pheno_ut(const Napi::CallbackInfo& info);

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * node_swe_refrac: (inalt: number, atpress: number, attemp: number, calc_flag: number) => number
 */
Napi::Number node_swe_refrac(const Napi::CallbackInfo& info);

/**
 * double swe_refrac_extended(double inalt, double geoalt, double atpress, double attemp, double lapse_rate, int32 calc_flag, double *dret)
 * =>
 * node_swe_refrac_extended: (inalt: number, geoalt: number, atpress: number, attemp: number, lapse_rate: number, calc_flag: number) => {
 *   refraction:				number,
 *   trueAltitude:			number,
 *   apparentAltitude:	number,
 *   horizonDip:				number
 * }
 */
Napi::Object node_swe_refrac_extended(const Napi::CallbackInfo& info);

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * node_swe_set_lapse_rate: (lapse_rate: number) => void
 */
Napi::Function::VoidCallback node_swe_set_lapse_rate(const Napi::CallbackInfo& info);

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos, double atpress, double attemp, double *xin, double *xaz)
 * =>
 * node_swe_azalt: (tjd_ut: number, calc_flag: number, longitude: number, latitude: number, height: number, atpress: number, attemp: number, bodyX: number, bodyY: number, bodyZ: number) => {
 *   azimuth:						number,
 *   trueAltitude:			number,
 *   apparentAltitude:	number
 * }
 */
Napi::Object node_swe_azalt(const Napi::CallbackInfo& info);

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos, double *xin, double *xout)
 * =>
 * node_swe_azalt_rev: (tjd_ut: number, calc_flag: number, longitude: number, latitude: number, height: number, bodyAzimuth: number, bodyTrueAltitude: number) => {
 *   azimuth:				number,
 *   trueAltitude:	number
 * }
 */
Napi::Object node_swe_azalt_rev(const Napi::CallbackInfo& info);

/**
 * int32 swe_rise_trans(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos, double atpress, double attemp, double *tret, char *serr)
 * =>
 * node_swe_rise_trans: (tjd_ut: number, ipl: number, starname: string, epheflag: number, rsmi: number, longitude: number, latitude: number, height: number, atpress: number, attemp: number) => {
 *   name:				string,
 *   transitTime:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_rise_trans(const Napi::CallbackInfo& info);

/**
 * int32 swe_rise_trans_true_hor(double tjd_ut, int32 ipl, char *starname, int32 epheflag, int32 rsmi, double *geopos (in[3]), double atpress, double attemp, double horhgt, double *tret (out[1]), char *serr (out[AS_MAXCH]))
 * =>
 * node_swe_rise_trans_true_hor: (tjd_ut: number, ipl: number, starname: string, epheflag: number, rsmi: number, longitude: number, latitude: number, height: number, atpress: number, horhgt: number, attemp: number) => {
 *   name:				string,
 *   transitTime:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_rise_trans_true_hor(const Napi::CallbackInfo& info);

#endif