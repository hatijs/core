#include "swisseph.h"

/**
 * int swe_houses(double tjd_ut, double geolat, double geolon, string hsys, double *cusps, double *ascmc)
 * =>
 * node_swe_houses: (tjd_ut: number, geolat: number, geolon: number, hsys: string) => {
 *   house: 									number[],
 *   ascendant:								number,
 *   mc:											number,
 *   armc:										number,
 *   vertex:									number,
 *   equatorialAscendant:			number,
 *   kochCoAscendant:					number,
 *   munkaseyCoAscendant:			number,
 *   munkaseyPolarAscendant:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Array house = Napi::Array::New(env);
	Napi::Object result = Napi::Object::New(env);

  double cusps[40] = {0};
  double ascmc[40] = {0};
	int hsys;

  size_t cuspsCount;
  int rflag;

  hsys = info[3].ToString().Utf8Value()[0];
  if (hsys == 'G') {
    cuspsCount = 36;
  }
  else {
    cuspsCount = 12;
  }

  rflag = ::swe_houses(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().DoubleValue(),
    hsys,
    cusps, ascmc
  );

  if (rflag < 0) {
    result.Set("error", "Can't calculate houses.");
  } else {
    for (size_t i = 0; i < cuspsCount; i++) {
      house.Set(i, cusps[i + 1]);
    }

    result.Set("house", house);
    result.Set("ascendant", ascmc[SE_ASC]);
    result.Set("mc", ascmc[SE_MC]);
    result.Set("armc", ascmc[SE_ARMC]);
    result.Set("vertex", ascmc[SE_VERTEX]);
    result.Set("equatorialAscendant", ascmc[SE_EQUASC]);
    result.Set("kochCoAscendant", ascmc[SE_COASC1]);
    result.Set("munkaseyCoAscendant", ascmc[SE_COASC2]);
    result.Set("munkaseyPolarAscendant", ascmc[SE_POLASC]);
  }

  return result;
}

/**
 * int swe_houses_ex(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc)
 * =>
 * node_swe_houses_ex: (tjd_ut: number, iflag: number, geolat: number, geolon: number, hsys: string) => {
 *   house:										number[],
 *   ascendant:								number,
 *   mc:											number,
 *   armc:										number,
 *   vertex:									number,
 *   equatorialAscendant:			number,
 *   kochCoAscendant:					number,
 *   munkaseyCoAscendant:			number,
 *   munkaseyPolarAscendant:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_ex(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 5) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
    !info[4].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

  Napi::Array house = Napi::Array::New(env);
	Napi::Object result = Napi::Object::New(env);

  double cusps[40] = {0};
  double ascmc[40] = {0};
	int hsys;

  size_t cuspsCount;
  int rflag;

  hsys = info[4].ToString().Utf8Value()[0];
  if (hsys == 'G') {
    cuspsCount = 36;
  }
  else {
    cuspsCount = 12;
  }

  rflag = ::swe_houses_ex(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().DoubleValue(),
    info[3].ToNumber().DoubleValue(),
    hsys,
    cusps, ascmc
  );

  if (rflag < 0) {
    result.Set("error", "Can't calculate houses.");
  } else {
    for (size_t i = 0; i < cuspsCount; i++) {
      house.Set(i, cusps[i + 1]);
    }

    result.Set("house", house);
    result.Set("ascendant", ascmc[SE_ASC]);
    result.Set("mc", ascmc[SE_MC]);
    result.Set("armc", ascmc[SE_ARMC]);
    result.Set("vertex", ascmc[SE_VERTEX]);
    result.Set("equatorialAscendant", ascmc[SE_EQUASC]);
    result.Set("kochCoAscendant", ascmc[SE_COASC1]);
    result.Set("munkaseyCoAscendant", ascmc[SE_COASC2]);
    result.Set("munkaseyPolarAscendant", ascmc[SE_POLASC]);
  }

  return result;
}

/**
 * int swe_houses_ex2(double tjd_ut, int32 iflag, double geolat, double geolon, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * node_swe_houses_ex2: (tjd_ut: number, iflag: number, geolat: number, geolon: number, hsys: string) => {
 *   house:												number[],
 *   ascendant:										number,
 *   mc:													number,
 *   armc:												number,
 *   vertex:											number,
 *   equatorialAscendant:					number,
 *   kochCoAscendant:							number,
 *   munkaseyCoAscendant:					number,
 *   munkaseyPolarAscendant:			number,
 *   houseSpeed:									number[],
 *   ascendantSpeed:							number,
 *   mcSpeed:											number,
 *   armcSpeed:										number,
 *   vertexSpeed:									number,
 *   equatorialAscendantSpeed:		number,
 *   kochCoAscendantSpeed:				number,
 *   munkaseyCoAscendantSpeed:		number,
 *   munkaseyPolarAscendantSpeed:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_ex2(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 5) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsNumber() ||
    !info[4].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

  Napi::Array house = Napi::Array::New(env);
  Napi::Array houseSpeed = Napi::Array::New(env);
	Napi::Object result = Napi::Object::New(env);

  double cusps[40] = {0};
  double ascmc[40] = {0};
  double cusps_speed[40] = {0};
  double ascmc_speed[40] = {0};
	int hsys;
	char serr[AS_MAXCH];

	size_t cuspsCount;
  int rflag;

  hsys = info[4].ToString().Utf8Value()[0];
  if (hsys == 'G') {
    cuspsCount = 36;
  }
  else {
    cuspsCount = 12;
  }

  rflag = ::swe_houses_ex2(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().DoubleValue(),
    info[3].ToNumber().DoubleValue(),
    hsys,
    cusps, ascmc, cusps_speed, ascmc_speed,
    serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    for (size_t i = 0; i < cuspsCount; i++) {
      house.Set(i, cusps[i + 1]);
      houseSpeed.Set(i, cusps_speed[i + 1]);
    }

    result.Set("house", house);
    result.Set("ascendant", ascmc[SE_ASC]);
    result.Set("mc", ascmc[SE_MC]);
    result.Set("armc", ascmc[SE_ARMC]);
    result.Set("vertex", ascmc[SE_VERTEX]);
    result.Set("equatorialAscendant", ascmc[SE_EQUASC]);
    result.Set("kochCoAscendant", ascmc[SE_COASC1]);
    result.Set("munkaseyCoAscendant", ascmc[SE_COASC2]);
    result.Set("munkaseyPolarAscendant", ascmc[SE_POLASC]);

    result.Set("houseSpeed", houseSpeed);
    result.Set("ascendantSpeed", ascmc_speed[SE_ASC]);
    result.Set("mcSpeed", ascmc_speed[SE_MC]);
    result.Set("armcSpeed", ascmc_speed[SE_ARMC]);
    result.Set("vertexSpeed", ascmc_speed[SE_VERTEX]);
    result.Set("equatorialAscendantSpeed", ascmc_speed[SE_EQUASC]);
    result.Set("kochCoAscendantSpeed", ascmc_speed[SE_COASC1]);
    result.Set("munkaseyCoAscendantSpeed", ascmc_speed[SE_COASC2]);
    result.Set("munkaseyPolarAscendantSpeed", ascmc_speed[SE_POLASC]);
  }

  return result;
}

/**
 * int swe_houses_armc(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc)
 * =>
 * node_swe_houses_armc: (armc: number, geolat: number, eps: number, hsys: string) => {
 *   house:										number[],
 *   ascendant:								number,
 *   mc:											number,
 *   armc:										number,
 *   vertex:									number,
 *   equatorialAscendant:			number,
 *   kochCoAscendant:					number,
 *   munkaseyCoAscendant:			number,
 *   munkaseyPolarAscendant:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_armc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  // 인자 타입
  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Array house = Napi::Array::New(env);
  Napi::Object result = Napi::Object::New(env);

	double cusps[40] = {0};
  double ascmc[40] = {0};
	int hsys;

  size_t cuspsCount;
  int rflag;

  hsys = info[3].ToString().Utf8Value()[0];
  if (hsys == 'G') {
    cuspsCount = 36;
  }
  else {
    cuspsCount = 12;
  }

  rflag = ::swe_houses_armc(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().DoubleValue(),
    hsys,
    cusps, ascmc
  );

  if (rflag < 0) {
    result.Set("error", "Can't calculate houses.");
  } else {
    for (size_t i = 0; i < cuspsCount; i++) {
      house.Set(i, cusps[i + 1]);
    }

    result.Set("house", house);
    result.Set("ascendant", ascmc[SE_ASC]);
    result.Set("mc", ascmc[SE_MC]);
    result.Set("armc", ascmc[SE_ARMC]);
    result.Set("vertex", ascmc[SE_VERTEX]);
    result.Set("equatorialAscendant", ascmc[SE_EQUASC]);
    result.Set("kochCoAscendant", ascmc[SE_COASC1]);
    result.Set("munkaseyCoAscendant", ascmc[SE_COASC2]);
    result.Set("munkaseyPolarAscendant", ascmc[SE_POLASC]);
  }

  return result;
}

/**
 * int swe_houses_armc_ex2(double armc, double geolat, double eps, int hsys, double *cusps, double *ascmc, double *cusps_speed, double *ascmc_speed, char *serr)
 * =>
 * node_swe_houses_armc_ex2: (armc: number, geolat: number, eps: number, hsys: string) => {
 *   house:												number[],
 *   ascendant:										number,
 *   mc:													number,
 *   armc:												number,
 *   vertex:											number,
 *   equatorialAscendant:					number,
 *   kochCoAscendant:							number,
 *   munkaseyCoAscendant:					number,
 *   munkaseyPolarAscendant:			number,
 *   houseSpeed:									number[],
 *   ascendantSpeed:							number,
 *   mcSpeed:											number,
 *   armcSpeed:										number,
 *   vertexSpeed:									number,
 *   equatorialAscendantSpeed:		number,
 *   kochCoAscendantSpeed:				number,
 *   munkaseyCoAscendantSpeed:		number,
 *   munkaseyPolarAscendantSpeed:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_armc_ex2(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 4) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  // 인자 타입
  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Array house = Napi::Array::New(env);
  Napi::Array houseSpeed = Napi::Array::New(env);
	Napi::Object result = Napi::Object::New(env);

  double cusps[40] = {0};
  double ascmc[40] = {0};
  double cusps_speed[40] = {0};
  double ascmc_speed[40] = {0};
	int hsys;
	char serr[AS_MAXCH];

  size_t cuspsCount;
  int rflag;

  hsys = info[3].ToString().Utf8Value()[0];
  if (hsys == 'G') {
    cuspsCount = 36;
  }
  else {
    cuspsCount = 12;
  }

  rflag = ::swe_houses_armc_ex2(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().DoubleValue(),
    hsys,
    cusps, ascmc, cusps_speed, ascmc_speed,
    serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    for (size_t i = 0; i < cuspsCount; i++) {
      house.Set(i, cusps[i + 1]);
      houseSpeed.Set(i, cusps_speed[i + 1]);
    }

    result.Set("house", house);
    result.Set("ascendant", ascmc[SE_ASC]);
    result.Set("mc", ascmc[SE_MC]);
    result.Set("armc", ascmc[SE_ARMC]);
    result.Set("vertex", ascmc[SE_VERTEX]);
    result.Set("equatorialAscendant", ascmc[SE_EQUASC]);
    result.Set("kochCoAscendant", ascmc[SE_COASC1]);
    result.Set("munkaseyCoAscendant", ascmc[SE_COASC2]);
    result.Set("munkaseyPolarAscendant", ascmc[SE_POLASC]);

    result.Set("houseSpeed", houseSpeed);
    result.Set("ascendantSpeed", ascmc_speed[SE_ASC]);
    result.Set("mcSpeed", ascmc_speed[SE_MC]);
    result.Set("armcSpeed", ascmc_speed[SE_ARMC]);
    result.Set("vertexSpeed", ascmc_speed[SE_VERTEX]);
    result.Set("equatorialAscendantSpeed", ascmc_speed[SE_EQUASC]);
    result.Set("kochCoAscendantSpeed", ascmc_speed[SE_COASC1]);
    result.Set("munkaseyCoAscendantSpeed", ascmc_speed[SE_COASC2]);
    result.Set("munkaseyPolarAscendantSpeed", ascmc_speed[SE_POLASC]);
  }

  return result;
}

/**
 * double swe_houses_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * node_swe_houses_pos: (armc: number, geolat: number, eps: number, hsys: string, lon: number, lat: number) => {
 *   housePosition:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_pos(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  // 인자 갯수
  if (info.Length() != 6) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  // 인자 타입
  if (
    !info[0].IsNumber() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber() ||
    !info[3].IsString() ||
    !info[4].IsNumber() ||
    !info[5].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);
	
  double xpin[2] = {0};
	char serr[AS_MAXCH];

  double rflag;

	xpin[0] = info[4].ToNumber().DoubleValue();
	xpin[1] = info[5].ToNumber().DoubleValue();

  rflag = ::swe_house_pos(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().DoubleValue(),
    info[3].ToString().Utf8Value()[0],
    xpin, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    result.Set("housePosition", rflag);
  }

  return result;
}