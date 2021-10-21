#include "swisseph.h"

/**
 * int swe_date_conversion(int y, int m, int d, double utime, char gregflag, double *tjd)
 * =>
 * node_swe_date_conversion: (year: number, month: number, day: number, hour: number, gregflag: number) => {
 *   julianDay:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_date_conversion(const Napi::CallbackInfo& info);

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * node_swe_julday: (year: number, month: number, day: number, hour: number, gregflag: number) => number
 */
Napi::Number node_swe_julday(const Napi::CallbackInfo& info);

/**
 * void swe_revjul (double jd, int gregflag, int *jyear, int *jmon, int *jday, double *jut)
 * =>
 * node_swe_revjul: (jd: number, gregflag: number) => {
 *   year:	number,
 *   month:	number,
 *   day:		number,
 *   hour:	number
 * }
 */
Napi::Object node_swe_revjul(const Napi::CallbackInfo& info);

/**
 * int32 swe_utc_to_jd(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, int32 gregflag, double *dret, char *serr)
 * =>
 * node_swe_utc_to_jd: (iyear: number, imonth: number, iday: number, ihour: number, imin: number, dsec: number, gregflag: number) => {
 *   julianDayET:	number,
 *   julianDayUT:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_utc_to_jd(const Napi::CallbackInfo& info);

/**
 * void swe_jdet_to_utc(double tjd_et, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * node_swe_jdet_to_utc: (tjd_et: number, gregflag: number) => {
 *   year:		number,
 *   month:		number,
 *   day:			number,
 *   hour:		number,
 *   minute:	number,
 *   second:	number
 * }
 */
Napi::Object node_swe_jdet_to_utc(const Napi::CallbackInfo& info);

/**
 * void swe_jdut1_to_utc(double tjd_ut, int32 gregflag, int32 *iyear, int32 *imonth, int32 *iday, int32 *ihour, int32 *imin, double *dsec)
 * =>
 * node_swe_jdut1_to_utc: (tjd_ut: number, gregflag: number) => {
 *   year:		number,
 *   month:		number,
 *   day:			number,
 *   hour:		number,
 *   minute:	number,
 *   second:	number
 * }
 */
Napi::Object node_swe_jdut1_to_utc(const Napi::CallbackInfo& info);

/**
 * void swe_utc_time_zone(int32 iyear, int32 imonth, int32 iday, int32 ihour, int32 imin, double dsec, double d_timezone, int32 *iyear_out, int32 *imonth_out, int32 *iday_out, int32 *ihour_out, int32 *imin_out, double *dsec_out)
 * =>
 * node_swe_utc_time_zone: (iyear: number, imonth: number, iday: number, ihour: number, imin: number, dsec: number, d_timezone: number) => {
 *   year:		number,
 *   month:		number,
 *   day:			number,
 *   hour:		number,
 *   minute:	number,
 *   second:	number
 * }
 */
Napi::Object node_swe_utc_time_zone(const Napi::CallbackInfo& info);