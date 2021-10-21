#include "swisseph.h"

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
Napi::Object node_swe_heliacal_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 7) {
    Napi::Error::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsArray() ||
    !info[2].IsArray() ||
    !info[3].IsArray() ||
    !info[4].IsString() ||
    !info[5].IsNumber() ||
    !info[6].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char name [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	dgeo[0] = info[1].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dgeo[1] = info[1].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dgeo[2] = info[1].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();

	datm[0] = info[2].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  datm[1] = info[2].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  datm[2] = info[2].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
	datm[3] = info[2].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();

	dobs[0] = info[3].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dobs[1] = info[3].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dobs[2] = info[3].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
  dobs[3] = info[3].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();
  dobs[4] = info[3].ToObject().Get((uint32_t)4).ToNumber().DoubleValue();
  dobs[5] = info[3].ToObject().Get((uint32_t)5).ToNumber().DoubleValue();

  ::strcpy(name, info[4].As<Napi::String>().Utf8Value().c_str());

  rflag = ::swe_heliacal_ut(
    info[0].ToNumber().DoubleValue(),
    dgeo, datm, dobs, name,
    info[5].ToNumber().Int32Value(),
    info[6].ToNumber().Int32Value(),
    dret, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  }
  else {
    result.Set("startVisible", dret[0]);
    result.Set("bestVisible", dret[1]);
    result.Set("endVisible", dret[2]);
  }

  return result;
}

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
Napi::Object node_swe_heliacal_pheno_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 7) {
    Napi::Error::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsArray() ||
    !info[2].IsArray() ||
    !info[3].IsArray() ||
    !info[4].IsString() ||
    !info[5].IsNumber() ||
    !info[6].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double darr [50] = {0};
	char name [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	dgeo[0] = info[1].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dgeo[1] = info[1].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dgeo[2] = info[1].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();

	datm[0] = info[2].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  datm[1] = info[2].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  datm[2] = info[2].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
	datm[3] = info[2].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();

	dobs[0] = info[3].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dobs[1] = info[3].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dobs[2] = info[3].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
  dobs[3] = info[3].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();
  dobs[4] = info[3].ToObject().Get((uint32_t)4).ToNumber().DoubleValue();
  dobs[5] = info[3].ToObject().Get((uint32_t)5).ToNumber().DoubleValue();

  ::strcpy(name, info[4].As<Napi::String>().Utf8Value().c_str());

  rflag = ::swe_heliacal_pheno_ut(
    info[0].ToNumber().DoubleValue(),
    dgeo, datm, dobs, name,
    info[5].ToNumber().Int32Value(),
    info[6].ToNumber().Int32Value(),
    darr, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  }
  else {
    result.Set("tcAltitude", darr[0]);
    result.Set("tcApparentAltitude", darr[1]);
    result.Set("gcAltitude", darr[2]);
    result.Set("azimuth", darr[3]);
    result.Set("tcSunAltitude", darr[4]);
    result.Set("sunAzimuth", darr[5]);
    result.Set("tcActualVisibleArc", darr[6]);
    result.Set("gcActualVisibleArc", darr[7]);
    result.Set("objectToSunAzimuth", darr[8]);
    result.Set("objectToSunLongitude", darr[9]);
    result.Set("extinction", darr[10]);
    result.Set("tcMinVisibleArc", darr[11]);
    result.Set("firstVisible", darr[12]);
    result.Set("bestVisible", darr[13]);
    result.Set("endVisible", darr[14]);
    result.Set("yallopBestVisible", darr[15]);
    result.Set("moonCresentWidth", darr[16]);
    result.Set("yallopValue", darr[17]);
    result.Set("yallopCriterion", darr[18]);
    result.Set("parallax", darr[19]);
    result.Set("magnitude", darr[20]);
    result.Set("rise", darr[21]);
    result.Set("riseSet", darr[22]);
    result.Set("riseObjectToSun", darr[23]);
    result.Set("visibleDuration", darr[24]);
    result.Set("moonCresetLength", darr[25]);
    result.Set("elong", darr[26]);
    result.Set("illumination", darr[27]);
    result.Set("kOZ", darr[28]);
    result.Set("ka", darr[29]);
    result.Set("ksumm", darr[30]);
  }

  return result;
}

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
Napi::Object node_swe_vis_limit_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsArray() ||
    !info[2].IsArray() ||
    !info[3].IsArray() ||
    !info[4].IsString() ||
    !info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
  double dgeo [3] = {0};
	double datm [4] = {0};
	double dobs [6] = {0};
	double dret [50] = {0};
	char name [AS_MAXCH];
	char serr [AS_MAXCH];
	long rflag;

	dgeo[0] = info[1].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dgeo[1] = info[1].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dgeo[2] = info[1].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();

	datm[0] = info[2].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  datm[1] = info[2].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  datm[2] = info[2].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
	datm[3] = info[2].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();

	dobs[0] = info[3].ToObject().Get((uint32_t)0).ToNumber().DoubleValue();
  dobs[1] = info[3].ToObject().Get((uint32_t)1).ToNumber().DoubleValue();
  dobs[2] = info[3].ToObject().Get((uint32_t)2).ToNumber().DoubleValue();
  dobs[3] = info[3].ToObject().Get((uint32_t)3).ToNumber().DoubleValue();
  dobs[4] = info[3].ToObject().Get((uint32_t)4).ToNumber().DoubleValue();
  dobs[5] = info[3].ToObject().Get((uint32_t)5).ToNumber().DoubleValue();

  ::strcpy(name, info[4].As<Napi::String>().Utf8Value().c_str());

  rflag = ::swe_vis_limit_mag(
    info[0].ToNumber().DoubleValue(),
    dgeo, datm, dobs, name,
    info[5].ToNumber().Int32Value(),
    dret, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  }
  else {
    result.Set("vissualMagnitudeLimit", dret[0]);
    result.Set("AltO", dret[1]);
    result.Set("AziO", dret[2]);
    result.Set("AltS", dret[3]);
    result.Set("AziS", dret[4]);
    result.Set("AltM", dret[5]);
    result.Set("AziM", dret[6]);
  }

  return result;
}