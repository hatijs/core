#ifndef __swisseph_util_h__
#define __swisseph_util_h__

/**
 * double swe_deltat(double tjd)
 * =>
 * node_swe_deltat: (tjd: number) => number
 */
Napi::Number node_swe_deltat(const Napi::CallbackInfo& info);

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 * =>
 * node_swe_time_equ: (tjd: number) => {
 *   timeEquation:	number
 * } | {
 *   error: string
 * }
 */
Napi::Object node_swe_time_equ(const Napi::CallbackInfo& info);

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * node_swe_sidtime0: (tjd_ut: number, eps: number, nut: number) => number
 */
Napi::Number node_swe_sidtime0(const Napi::CallbackInfo& info);

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * node_swe_sidtime: (tjd_ut: double) => number
 */
Napi::Number node_swe_sidtime(const Napi::CallbackInfo& info);

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 * =>
 * node_swe_cotrans: (xpo: number[], eps: number) => {
 *   longitude:	number,
 *   latitude:	number,
 *   distance:	number
 * }
 */
Napi::Object node_swe_cotrans(const Napi::CallbackInfo& info);

/**
 * void swe_cotrans_sp(double *xpo, double *xpn, double eps)
 * =>
 * node_swe_cotrans_sp: (xpo: number[], eps: number) => {
 *   longitude:				number,
 *   latitude:				number,
 *   distance:				number,
 *   longitudeSpeed:	number,
 *   latitudeSpeed:		number,
 *   distanceSpeed:		number
 * }
 */
Napi::Object node_swe_cotrans_sp(const Napi::CallbackInfo& info);

/**
 * double swe_get_tid_acc(void)
 * =>
 * node_swe_get_tid_acc: () => number
 */
Napi::Number node_swe_get_tid_acc(const Napi::CallbackInfo& info);

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * node_swe_set_tid_acc: (t_acc: number) => {
 * }
 */
Napi::Object node_swe_set_tid_acc(const Napi::CallbackInfo& info);

/**
 * double swe_degnorm(double x)
 * =>
 * node_swe_degnorm: (x: number) => number
 */
Napi::Number node_swe_degnorm(const Napi::CallbackInfo& info);

/**
 * double swe_radnorm(double x)
 * =>
 * node_swe_radnorm: (x: number) => number
 */
Napi::Number node_swe_radnorm(const Napi::CallbackInfo& info);

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * node_swe_rad_midp: (x1: number, x0: number) => number
 */
Napi::Number node_swe_rad_midp(const Napi::CallbackInfo& info);

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * node_swe_deg_midp: (x1: number, x0: number) => number
 */
Napi::Number node_swe_deg_midp(const Napi::CallbackInfo& info);

/**
 * void swe_split_deg(double ddeg, int32 roundflag, int32 *ideg, int32 *imin, int32 *isec, double *dsecfr, int32 *isgn)
 * =>
 * node_swe_split_deg: (ddeg: number, roundflag: number) => {
 *   degree:					number,
 *   min:							number,
 *   second:					number,
 *   secondFraction:	number,
 *   sign:						number
 * }
 */
Napi::Object node_swe_split_deg(const Napi::CallbackInfo& info);

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * node_swe_csnorm: (p: number) => number
 */
Napi::Number node_swe_csnorm(const Napi::CallbackInfo& info);

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * node_swe_difcsn: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difcsn (const Napi::CallbackInfo& info);

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * node_swe_difdegn: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difdegn (const Napi::CallbackInfo& info);

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * node_swe_difcs2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difcs2n(const Napi::CallbackInfo& info);

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * node_swe_difdeg2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difdeg2n(const Napi::CallbackInfo& info);

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * node_swe_difrad2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difrad2n(const Napi::CallbackInfo& info);

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * node_swe_csroundsec: (x: number) => number
 */
Napi::Number node_swe_csroundsec(const Napi::CallbackInfo& info);

/**
 * int32 swe_d2l(double x)
 * =>
 * node_swe_d2l: (x: number) => number
 */
Napi::Number node_swe_d2l(const Napi::CallbackInfo& info);

/**
 * int swe_day_of_week(double jd)
 * =>
 * node_swe_day_of_week: (jd: number) => number
 */
Napi::Number node_swe_day_of_week(const Napi::CallbackInfo& info);

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 * =>
 * node_swe_cs2timestr: (t: number, sep: number, suppressZero: number) => string
 */
Napi::String node_swe_cs2timestr(const Napi::CallbackInfo& info);

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 * =>
 * node_swe_cs2lonlatstr: (t: number, pchar: string, mchar: string) => string
 */
Napi::String node_swe_cs2lonlatstr(const Napi::CallbackInfo& info);

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 * =>
 * node_swe_cs2degstr: (t: number) => string
 */
Napi::String node_swe_cs2degstr(const Napi::CallbackInfo& info);

#endif