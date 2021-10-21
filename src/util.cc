#include "swisseph.h"

/**
 * double swe_deltat(double tjd)
 * =>
 * node_swe_deltat: (tjd: number) => number
 */
Napi::Number node_swe_deltat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_deltat(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * int swe_time_equ(double tjd, double *te, char *serr)
 * =>
 * node_swe_time_equ: (tjd: number) => {
 *   timeEquation:	number
 * } | {
 *   error: string
 * }
 */
Napi::Object node_swe_time_equ(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double te;
	char serr[AS_MAXCH];

	long rflag;

	rflag = ::swe_time_equ(
		info[0].ToNumber().DoubleValue(),
		&te, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("timeEquation", te);
	}

	return result;
}

/**
 * double swe_sidtime0(double tjd_ut, double eps, double nut)
 * =>
 * node_swe_sidtime0: (tjd_ut: number, eps: number, nut: number) => number
 */
Napi::Number node_swe_sidtime0(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
		!info[1].IsNumber() ||
		!info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_sidtime0(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue(),
		info[2].ToNumber().DoubleValue()
	));
}

/**
 * double swe_sidtime(double tjd_ut)
 * =>
 * node_swe_sidtime: (tjd_ut: double) => number
 */
Napi::Number node_swe_sidtime(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_sidtime(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * void swe_cotrans(double *xpo, double *xpn, double eps)
 * =>
 * node_swe_cotrans: (xpo: number[], eps: number) => {
 *   longitude:	number,
 *   latitude:	number,
 *   distance:	number
 * }
 */
Napi::Object node_swe_cotrans(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsArray() ||
		!info[1].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double xpo[3] = {0};

	double xpn[3] = {0};

	xpo[0] = info[0].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
	xpo[1] = info[0].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
	xpo[2] = info[0].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();

	::swe_cotrans(
		xpo, xpn,
		info[1].ToNumber().DoubleValue()
	);

	result.Set("longitude", xpn[0]);
	result.Set("latitude", xpn[1]);
	result.Set("distance", xpn[2]);

	return result;
}

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
Napi::Object node_swe_cotrans_sp(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsArray() ||
		!info[1].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double xpo[6] = {0};

	double xpn[6] = {0};

	xpo[0] = info[0].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
	xpo[1] = info[0].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
	xpo[2] = info[0].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
	xpo[3] = info[0].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();
	xpo[4] = info[0].ToObject().Get((uint32_t)4).ToNumber().DoubleValue();
	xpo[5] = info[0].ToObject().Get((uint32_t)5).ToNumber().DoubleValue();

	::swe_cotrans_sp(
		xpo, xpn,
		info[1].ToNumber().DoubleValue()
	);

	result.Set("longitude", xpn[0]);
	result.Set("latitude", xpn[1]);
	result.Set("distance", xpn[2]);
	result.Set("longitudeSpeed", xpn[0]);
	result.Set("latitudeSpeed", xpn[1]);
	result.Set("distanceSpeed", xpn[2]);

	return result;
}

/**
 * double swe_get_tid_acc(void)
 * =>
 * node_swe_get_tid_acc: () => number
 */
Napi::Number node_swe_get_tid_acc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	return Napi::Number::New(env, ::swe_get_tid_acc());
}

/**
 * void swe_set_tid_acc(double t_acc)
 * =>
 * node_swe_set_tid_acc: (t_acc: number) => {
 * }
 */
Napi::Object node_swe_set_tid_acc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	::swe_set_tid_acc(
		info[0].ToNumber().DoubleValue()
	);

	return Napi::Object::New(env);
}

/**
 * double swe_degnorm(double x)
 * =>
 * node_swe_degnorm: (x: number) => number
 */
Napi::Number node_swe_degnorm(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_degnorm(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * double swe_radnorm(double x)
 * =>
 * node_swe_radnorm: (x: number) => number
 */
Napi::Number node_swe_radnorm(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_radnorm(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * double swe_rad_midp(double x1, double x0)
 * =>
 * node_swe_rad_midp: (x1: number, x0: number) => number
 */
Napi::Number node_swe_rad_midp(const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_rad_midp(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue()
	));
}

/**
 * double swe_deg_midp(double x1, double x0)
 * =>
 * node_swe_deg_midp: (x1: number, x0: number) => number
 */
Napi::Number node_swe_deg_midp(const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_deg_midp(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue()
	));
}

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
Napi::Object node_swe_split_deg(const Napi::CallbackInfo& info) {
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

	int ideg, imin, isec;
	double dsecfr;
	int isgn;

	::swe_split_deg(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		&ideg, &imin, &isec, &dsecfr, &isgn
	);

	result.Set("degree", ideg);
	result.Set("min", imin);
	result.Set("second", isec);
	result.Set("secondFraction", dsecfr);
	result.Set("sign", isgn);

	return result;
}

/**
 * centisec swe_csnorm(centisec p)
 * =>
 * node_swe_csnorm: (p: number) => number
 */
Napi::Number node_swe_csnorm(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_csnorm(
		info[0].ToNumber().Int32Value()
	));
}

/**
 * centisec swe_difcsn (centisec p1, centisec p2)
 * =>
 * node_swe_difcsn: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difcsn (const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_difcsn(
		info[0].ToNumber().Int32Value(),
		info[1].ToNumber().Int32Value()
	));
}

/**
 * double swe_difdegn (double p1, double p2)
 * =>
 * node_swe_difdegn: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difdegn (const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_difdegn(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue()
	));
}

/**
 * centisec swe_difcs2n(centisec p1, centisec p2)
 * =>
 * node_swe_difcs2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difcs2n(const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_difcs2n(
		info[0].ToNumber().Int32Value(),
		info[1].ToNumber().Int32Value()
	));
}

/**
 * double swe_difdeg2n(double p1, double p2)
 * =>
 * node_swe_difdeg2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difdeg2n(const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_difdeg2n(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue()
	));
}

/**
 * double swe_difrad2n(double p1, double p2)
 * =>
 * node_swe_difrad2n: (p1: number, p2: number) => number
 */
Napi::Number node_swe_difrad2n(const Napi::CallbackInfo& info) {
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

	return Napi::Number::New(env, ::swe_difrad2n(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue()
	));
}

/**
 * centisec swe_csroundsec(centisec x)
 * =>
 * node_swe_csroundsec: (x: number) => number
 */
Napi::Number node_swe_csroundsec(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_csroundsec(
		info[0].ToNumber().Int32Value()
	));
}

/**
 * int32 swe_d2l(double x)
 * =>
 * node_swe_d2l: (x: number) => number
 */
Napi::Number node_swe_d2l(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_d2l(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * int swe_day_of_week(double jd)
 * =>
 * node_swe_day_of_week: (jd: number) => number
 */
Napi::Number node_swe_day_of_week(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_day_of_week(
		info[0].ToNumber().DoubleValue()
	));
}

/**
 * char * swe_cs2timestr(CSEC t, int sep, AS_BOOL suppressZero, char *a)
 * =>
 * node_swe_cs2timestr: (t: number, sep: number, suppressZero: number) => string
 */
Napi::String node_swe_cs2timestr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
		!info[1].IsNumber() ||
		!info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char timeString[AS_MAXCH] = {0};

	::swe_cs2timestr(
		info[0].ToNumber().Int32Value(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		timeString
	);

	return Napi::String::New(env, timeString);
}

/**
 * char * swe_cs2lonlatstr(CSEC t, char pchar, char mchar, char *s)
 * =>
 * node_swe_cs2lonlatstr: (t: number, pchar: string, mchar: string) => string
 */
Napi::String node_swe_cs2lonlatstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
		!info[1].IsString() ||
		!info[2].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char lonlatString[AS_MAXCH] = {0};

	::swe_cs2lonlatstr(
		info[0].ToNumber().Int32Value(),
		info[1].ToString().Utf8Value().c_str()[0],
		info[2].ToString().Utf8Value().c_str()[0],
		lonlatString
	);

	return Napi::String::New(env, lonlatString);
}

/**
 * char * swe_cs2degstr(CSEC t, char *a)
 * =>
 * node_swe_cs2degstr: (t: number) => string
 */
Napi::String node_swe_cs2degstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char degreeString[AS_MAXCH] = {0};

	::swe_cs2degstr(
		info[0].ToNumber().Int32Value(),
		degreeString
	);

	return Napi::String::New(env, degreeString);
}