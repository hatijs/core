#ifndef __swisseph_hel_h__
#define __swisseph_hel_h__

/**
 * int32 swe_heliacal_ut(double tjdstart_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 iflag, double *dret, char *serr);
 * =>
 * node_swe_heliacal_ut: (tjdstart_ut: number, geopos: number[], datm: number[], dobs: number[], ObjectName: string, TypeEvent: number, iflag: number) => {
 *   startVisible:	number,
 *   bestVisible:		number,
 *   endVisible:		number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_heliacal_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_heliacal_pheno_ut(double tjd_ut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 TypeEvent, int32 helflag, double *darr, char *serr)
 * =>
 * node_swe_heliacal_pheno_ut: (tjd_ut: number, geopos: number[], datm: number[], dobs: number[], ObjectName: string, TypeEvent: number, helflag: number) => {
 *   tcAltitude:						number,
 *   tcApparentAltitude:		number,
 *   gcAltitude:						number,
 *   azimuth:								number,
 *   tcSunAltitude:					number,
 *   sunAzimuth:						number,
 *   tcActualVisibleArc:		number,
 *   gcActualVisibleArc:		number,
 *   objectToSunAzimuth:		number,
 *   objectToSunLongitude:	number,
 *   extinction:						number,
 *   tcMinVisibleArc:				number,
 *   firstVisible:					number,
 *   bestVisible:						number,
 *   endVisible:						number,
 *   yallopBestVisible:			number,
 *   moonCresentWidth:			number,
 *   yallopValue:						number,
 *   yallopCriterion:				number,
 *   parallax:							number,
 *   magnitude:							number,
 *   rise:									number,
 *   riseSet:								number,
 *   riseObjectToSun:				number,
 *   visibleDuration:				number,
 *   moonCresetLength:			number,
 *   elong:									number,
 *   illumination:					number,
 *   kOZ:										number,
 *   ka:										number,
 *   ksumm:									number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_heliacal_pheno_ut(const Napi::CallbackInfo& info);

/**
 * int32 swe_vis_limit_mag(double tjdut, double *geopos, double *datm, double *dobs, char *ObjectName, int32 helflag, double *dret, char *serr)
 * =>
 * node_swe_vis_limit_mag: (tjdut: number, geopos: number[], datm: number[], dobs: number[], ObjectName: string, helflag: number) => {
 *   vissualMagnitudeLimit:	number,
 *   AltO:									number,
 *   AziO:									number,
 *   AltS:									number,
 *   AziS:									number,
 *   AltM:									number,
 *   AziM:									number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_vis_limit_mag(const Napi::CallbackInfo& info);

#endif