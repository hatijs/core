#include "swisseph.h"

/**
 * int swe_date_conversion(int y, int m, int d, double utime, char gregflag, double *tjd)
 * =>
 * node_swe_date_conversion: (year: number, month: number, day: number, hour: number, gregflag: string) => {
 *   julianDay:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_date_conversion(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 5) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
  	!info[4].IsString() || 
		(info[4].ToString().Utf8Value().c_str()[0] != 'g' && info[4].ToString().Utf8Value().c_str()[0] != 'j')
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double tjd;
	int rflag;

	rflag = ::swe_date_conversion(
    info[0].ToNumber().Int32Value(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().Int32Value(),
    info[3].ToNumber().DoubleValue(),
    info[4].ToString().Utf8Value().c_str()[0],
    &tjd
  );

	if (rflag < 0) {
		result.Set("error", "Input date is illegal.");
	}
	else {
		result.Set("julianDay", tjd);
	}

	return result;
}

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * node_swe_julday: (year: number, month: number, day: number, hour: number, gregflag: number) => number
 */
Napi::Number node_swe_julday(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 5) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
    !info[4].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_julday(
    info[0].ToNumber(),
    info[1].ToNumber(),
    info[2].ToNumber(),
    info[3].ToNumber(),
    info[4].ToNumber()
  ));
}

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
Napi::Object node_swe_revjul(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  int year, month, day;
	double hour;

	::swe_revjul(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    &year, &month, &day, &hour
  );

	result.Set("year", year);
  result.Set("month", month);
  result.Set("day", day);
  result.Set("hour", hour);

	return result;
}

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
Napi::Object node_swe_utc_to_jd(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 7) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
    !info[4].IsNumber() ||
    !info[5].IsNumber() ||
    !info[6].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double tjd[2];
  char serr[AS_MAXCH];
  int rflag;

	rflag = ::swe_utc_to_jd(
    info[0].ToNumber().Int32Value(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().Int32Value(),
    info[3].ToNumber().Int32Value(),
    info[4].ToNumber().Int32Value(),
    info[5].ToNumber().DoubleValue(),
    info[6].ToNumber().Int32Value(),
    tjd, serr
  );

	if (rflag < 0) {
    result.Set("error", serr);
  }
  else {
    result.Set("julianDayET", tjd[0]);
    result.Set("julianDayUT", tjd[1]);
  }

	return result;
}

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
Napi::Object node_swe_jdet_to_utc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	int year, month, day, hour, minute;
	double second;

	::swe_jdet_to_utc(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    &year, &month, &day, &hour, &minute, &second
  );

	result.Set("year", year);
  result.Set("month", month);
  result.Set("day", day);
  result.Set("hour", hour);
  result.Set("minute", minute);
  result.Set("second", second);

	return result;
}

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
Napi::Object node_swe_jdut1_to_utc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  int year, month, day, hour, minute;
	double second;

  ::swe_jdut1_to_utc(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    &year, &month, &day, &hour, &minute, &second
  );

  result.Set("year", year);
  result.Set("month", month);
  result.Set("day", day);
  result.Set("hour", hour);
  result.Set("minute", minute);
  result.Set("second", second);

  return result;
}

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
Napi::Object node_swe_utc_time_zone(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 7) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
    !info[4].IsNumber() ||
    !info[5].IsNumber() ||
    !info[6].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  int year, month, day, hour, minute;
	double second;

  ::swe_utc_time_zone(
    info[0].ToNumber().Int32Value(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().Int32Value(),
    info[3].ToNumber().Int32Value(),
    info[4].ToNumber().Int32Value(),
    info[5].ToNumber().DoubleValue(),
    info[6].ToNumber().DoubleValue(),
    &year, &month, &day, &hour, &minute, &second
  );

  result.Set("year", year);
  result.Set("month", month);
  result.Set("day", day);
  result.Set("hour", hour);
  result.Set("minute", minute);
  result.Set("second", second);

  return result;
}