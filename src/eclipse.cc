#include "swisseph.h"

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
Napi::Object node_swe_gauquelin_sector(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 10) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsString() ||
    !info[3].IsNumber() ||
    !info[4].IsNumber() ||
    !info[5].IsNumber() ||
    !info[6].IsNumber() ||
    !info[7].IsNumber() ||
    !info[8].IsNumber() ||
    !info[9].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double dgsect;
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[5].ToNumber().DoubleValue();
	geopos[1] =	info[6].ToNumber().DoubleValue();
	geopos[2] = info[7].ToNumber().DoubleValue();

	::strcpy(star, info[2].As<Napi::String>().Utf8Value().c_str());

	rflag = ::swe_gauquelin_sector(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		info[4].ToNumber().Int32Value(),
		geopos,
		info[8].ToNumber().DoubleValue(),
		info[9].ToNumber().DoubleValue(),
		&dgsect, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("name", star);
		result.Set("gauquelinSector", dgsect);
	}

	return result;
}

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
Napi::Object node_swe_sol_eclipse_where(const Napi::CallbackInfo& info) {
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
	double geopos[10] = {0};
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_where(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("longitude", geopos[0]);
		result.Set("latitude", geopos[1]);
		result.Set("solarDiameterFraction", attr[0]);
		result.Set("lonarToSolarDiameterRatio", attr[1]);
		result.Set("solarDiscFraction", attr[2]);
		result.Set("coreShadow", attr[3]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("eclipseMagnitude", attr[8]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_lun_occult_where(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsString() ||
		!info[3].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double attr[20] = {0};
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	::strcpy(star, info[2].As<Napi::String>().Utf8Value().c_str());

	rflag = ::swe_lun_occult_where(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		geopos, attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("longitude", geopos[0]);
		result.Set("latitude", geopos[1]);
		result.Set("solarDiameterFraction", attr[0]);
		result.Set("lonarToSolarDiameterRatio", attr[1]);
		result.Set("solarDiscFraction", attr[2]);
		result.Set("coreShadow", attr[3]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
	}

	return result;
}

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
Napi::Object node_swe_sol_eclipse_how(const Napi::CallbackInfo& info) {
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

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	rflag = ::swe_sol_eclipse_how(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("solarDiameterFraction", attr[0]);
		result.Set("lonarToSolarDiameterRatio", attr[1]);
		result.Set("solarDiscFraction", attr[2]);
		result.Set("coreShadow", attr[3]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("eclipseMagnitude", attr[8]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_sol_eclipse_when_loc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double tret[10] = {0};
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	rflag = ::swe_sol_eclipse_when_loc(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, tret, attr,
		info[5].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("maximum", tret[0]);
		result.Set("first", tret[1]);
		result.Set("second", tret[2]);
		result.Set("third", tret[3]);
		result.Set("forth", tret[4]);
		result.Set("solarDiameterFraction", attr[0]);
		result.Set("lonarToSolarDiameterRatio", attr[1]);
		result.Set("solarDiscFraction", attr[2]);
		result.Set("coreShadow", attr[3]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("eclipseMagnitude", attr[8]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_lun_occult_when_loc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 8) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsString() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber() ||
		!info[6].IsNumber() ||
		!info[7].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double tret[10] = {0};
	double attr[20] = {0};
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[4].ToNumber().DoubleValue();
	geopos[1] =	info[5].ToNumber().DoubleValue();
	geopos[2] = info[6].ToNumber().DoubleValue();

	::strcpy(star, info[2].ToString().Utf8Value().c_str());

	rflag = ::swe_lun_occult_when_loc(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		geopos, tret, attr,
		info[7].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("name", star);
		result.Set("maximum", tret[0]);
		result.Set("first", tret[1]);
		result.Set("second", tret[2]);
		result.Set("third", tret[3]);
		result.Set("forth", tret[4]);
		result.Set("solarDiameterFraction", attr[0]);
		result.Set("lonarToSolarDiameterRatio", attr[1]);
		result.Set("solarDiscFraction", attr[2]);
		result.Set("coreShadow", attr[3]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("eclipseMagnitude", attr[8]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_sol_eclipse_when_glob(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double tret[10] = {0};
	char serr[AS_MAXCH];
	long rflag;

	rflag = ::swe_sol_eclipse_when_glob(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		tret,
		info[3].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("maximum", tret[0]);
		result.Set("noon", tret[1]);
		result.Set("begin", tret[2]);
		result.Set("end", tret[3]);
		result.Set("totalBegin", tret[4]);
		result.Set("totalEnd", tret[5]);
		result.Set("centerBegin", tret[6]);
		result.Set("centerEnd", tret[7]);
	}

	return result;
}

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
Napi::Object node_swe_lun_occult_when_glob(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsString() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double tret[10] = {0};
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	::strcpy(star, info[2].ToString().Utf8Value().c_str());

	rflag = ::swe_lun_occult_when_glob(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		info[4].ToNumber().Int32Value(),
		tret,
		info[5].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("name", star);
		result.Set("maximum", tret[0]);
		result.Set("noon", tret[1]);
		result.Set("begin", tret[2]);
		result.Set("end", tret[3]);
		result.Set("totalBegin", tret[4]);
		result.Set("totalEnd", tret[5]);
		result.Set("centerBegin", tret[6]);
		result.Set("centerEnd", tret[7]);
	}

	return result;
}

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
Napi::Object node_swe_lun_eclipse_how(const Napi::CallbackInfo& info) {
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

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	rflag = ::swe_lun_eclipse_how(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("umbralMagnitude", attr[0]);
		result.Set("penumbralMagnitude", attr[1]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("eclipseMagnitude", attr[8]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_lun_eclipse_when(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double tret[10] = {0};
	char serr[AS_MAXCH];
	long rflag;

	rflag = ::swe_lun_eclipse_when(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		tret,
		info[3].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("maximum", tret[0]);
		result.Set("partialBegin", tret[2]);
		result.Set("partialEnd", tret[3]);
		result.Set("totalBegin", tret[4]);
		result.Set("totalEnd", tret[5]);
		result.Set("penumbralBegin", tret[6]);
		result.Set("penumbralEnd", tret[7]);
	}

	return result;
}

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
Napi::Object node_swe_lun_eclipse_when_loc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double tret[10] = {0};
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	rflag = ::swe_lun_eclipse_when_loc(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, tret, attr,
		info[5].ToNumber().Int32Value(),
		serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("maximum", tret[0]);
		result.Set("partialBegin", tret[2]);
		result.Set("partialEnd", tret[3]);
		result.Set("totalBegin", tret[4]);
		result.Set("totalEnd", tret[5]);
		result.Set("penumbralBegin", tret[6]);
		result.Set("penumbralEnd", tret[7]);
		result.Set("moonRise", tret[8]);
		result.Set("moonSet", tret[9]);
		result.Set("umbralMagnitude", attr[0]);
		result.Set("penumbralMagnitude", attr[1]);
		result.Set("azimuth", attr[4]);
		result.Set("trueAltitude", attr[5]);
		result.Set("apparentAltitude", attr[6]);
		result.Set("moonToSunAngularDistance", attr[7]);
		result.Set("sarosNumber", attr[9]);
		result.Set("sarosMember", attr[10]);
	}

	return result;
}

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
Napi::Object node_swe_pheno(const Napi::CallbackInfo& info) {
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

	Napi::Object result = Napi::Object::New(env);
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("phaseAngle", attr[0]);
		result.Set("phase", attr[1]);
		result.Set("elongation", attr[2]);
		result.Set("apparentDiameter", attr[3]);
		result.Set("apparentMagnitude", attr[4]);
	}

	return result;
}

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
Napi::Object node_swe_pheno_ut(const Napi::CallbackInfo& info) {
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

	Napi::Object result = Napi::Object::New(env);
	double attr[20] = {0};
	char serr[AS_MAXCH];
	long rflag;

	rflag = ::swe_pheno_ut(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		attr, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("phaseAngle", attr[0]);
		result.Set("phase", attr[1]);
		result.Set("elongation", attr[2]);
		result.Set("apparentDiameter", attr[3]);
		result.Set("apparentMagnitude", attr[4]);
	}

	return result;
}

/**
 * double swe_refrac(double inalt, double atpress, double attemp, int32 calc_flag)
 * =>
 * node_swe_refrac: (inalt: number, atpress: number, attemp: number, calc_flag: number) => number
 */
Napi::Number node_swe_refrac(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	return Napi::Number::New(env, ::swe_refrac(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue(),
		info[2].ToNumber().DoubleValue(),
		info[3].ToNumber().Int32Value()
	));
}

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
Napi::Object node_swe_refrac_extended(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber() ||
    !info[4].IsNumber() ||
		!info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double dret[4] = {0};
	double refrection;

	refrection = ::swe_refrac_extended(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue(),
		info[2].ToNumber().DoubleValue(),
		info[3].ToNumber().DoubleValue(),
		info[4].ToNumber().DoubleValue(),
		info[5].ToNumber().Int32Value(),
		dret
	);

	result.Set("refraction", refrection);
	result.Set("trueAltitude", dret[0]);
	result.Set("apparentAltitude", dret[1]);
	result.Set("horizonDip", dret[3]);

	return result;
}

/**
 * void swe_set_lapse_rate(double lapse_rate)
 * =>
 * node_swe_set_lapse_rate: (lapse_rate: number) => {}
 */
Napi::Object node_swe_set_lapse_rate(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	::swe_set_lapse_rate(
		info[0].ToNumber().DoubleValue()
	);

	return Napi::Object::New(env);
}

/**
 * void swe_azalt(double tjd_ut, int32 calc_flag, double *geopos, double atpress, double attemp, double *xin, double *xaz)
 * =>
 * node_swe_azalt: (tjd_ut: number, calc_flag: number, longitude: number, latitude: number, height: number, atpress: number, attemp: number, bodyX: number, bodyY: number, bodyZ: number) => {
 *   azimuth:						number,
 *   trueAltitude:			number,
 *   apparentAltitude:	number
 * }
 */
Napi::Object node_swe_azalt(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 10) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
		!info[1].IsNumber() ||
		!info[2].IsNumber() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber() ||
		!info[6].IsNumber() ||
		!info[7].IsNumber() ||
		!info[8].IsNumber() ||
		!info[9].IsNumber() 
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double xin[3] = {0};
	double xaz[3] = {0};

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	xin[0] = info[7].ToNumber().DoubleValue();
	xin[1] = info[8].ToNumber().DoubleValue();
	xin[2] = info[9].ToNumber().DoubleValue();

	::swe_azalt(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos,
		info[5].ToNumber().DoubleValue(),
		info[6].ToNumber().DoubleValue(),
		xin, xaz
	);

	result.Set("azimuth", xaz[0]);
	result.Set("trueAltitude", xaz[1]);
	result.Set("apparentAltitude", xaz[2]);

	return result;
}

/**
 * void swe_azalt_rev(double tjd_ut, int32 calc_flag, double *geopos, double *xin, double *xout)
 * =>
 * node_swe_azalt_rev: (tjd_ut: number, calc_flag: number, longitude: number, latitude: number, height: number, bodyAzimuth: number, bodyTrueAltitude: number) => {
 *   azimuth:				number,
 *   trueAltitude:	number
 * }
 */
Napi::Object node_swe_azalt_rev(const Napi::CallbackInfo& info) {
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
	double geopos[10] = {0};
	double xin[3] = {0};
	double xout[3] = {0};

	geopos[0] = info[2].ToNumber().DoubleValue();
	geopos[1] =	info[3].ToNumber().DoubleValue();
	geopos[2] = info[4].ToNumber().DoubleValue();

	xin[0] = info[5].ToNumber().DoubleValue();
	xin[1] = info[6].ToNumber().DoubleValue();

	::swe_azalt_rev(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		geopos, xin, xout
	);

	result.Set("azimuth", xout[0]);
	result.Set("trueAltitude", xout[1]);

	return result;
}

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
Napi::Object node_swe_rise_trans(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 10) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsString() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber() ||
		!info[6].IsNumber() ||
		!info[7].IsNumber() ||
		!info[8].IsNumber() ||
		!info[9].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double tret;
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[5].ToNumber().DoubleValue();
	geopos[1] =	info[6].ToNumber().DoubleValue();
	geopos[2] = info[7].ToNumber().DoubleValue();

	::strcpy(star, info[2].ToString().Utf8Value().c_str());

	rflag = ::swe_rise_trans(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		info[4].ToNumber().Int32Value(),
		geopos,
		info[8].ToNumber().DoubleValue(),
		info[9].ToNumber().DoubleValue(),
		&tret, serr
	);

	if (rflag == -1) {
		result.Set("error", serr);
	}
	else {
		if (rflag == -2)
			tret = -2;

		result.Set("name", star);
		result.Set("transitTime", tret);
	}

	return result;
}

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
Napi::Object node_swe_rise_trans_true_hor(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 11) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

	if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
		!info[2].IsString() ||
		!info[3].IsNumber() ||
		!info[4].IsNumber() ||
		!info[5].IsNumber() ||
		!info[6].IsNumber() ||
		!info[7].IsNumber() ||
		!info[8].IsNumber() ||
		!info[9].IsNumber() ||
		!info[10].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	double geopos[10] = {0};
	double tret;
	char star[AS_MAXCH];
	char serr[AS_MAXCH];
	long rflag;

	geopos[0] = info[5].ToNumber().DoubleValue();
	geopos[1] =	info[6].ToNumber().DoubleValue();
	geopos[2] = info[7].ToNumber().DoubleValue();

	::strcpy(star, info[2].ToString().Utf8Value().c_str());

	rflag = ::swe_rise_trans_true_hor(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		star,
		info[3].ToNumber().Int32Value(),
		info[4].ToNumber().Int32Value(),
		geopos,
		info[8].ToNumber().DoubleValue(),
		info[9].ToNumber().DoubleValue(),
		info[10].ToNumber().DoubleValue(),
		&tret, serr
	);

	if (rflag == -1) {
		result.Set("error", serr);
	}
	else {
		if (rflag == -2)
			tret = -2;

		result.Set("name", star);
		result.Set("transitTime", tret);
	}

	return result;
}
