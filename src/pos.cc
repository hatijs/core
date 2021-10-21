#include "swisseph.h"

/**
 * char swe_version(char *)
 * =>
 * node_swe_version: () => string
 */
Napi::String node_swe_version(const Napi::CallbackInfo& info) {
  char version [AS_MAXCH];
	
  return Napi::String::New(info.Env(), ::swe_version(version));
}

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
Napi::Object node_swe_calc(const Napi::CallbackInfo& info) {
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

	double x[6];
  char serr[AS_MAXCH];

  long rflag;

  rflag = ::swe_calc(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
  }

  return result;
}

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
Napi::Object node_swe_calc_ut(const Napi::CallbackInfo& info) {
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

	double x[6];
  char serr[AS_MAXCH];

  long rflag;

  rflag = ::swe_calc_ut(
    info[0].ToNumber().DoubleValue(),
    info[1].ToNumber().Int32Value(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
  }

  return result;
}

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
Napi::Object node_swe_fixstar(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double x[6];
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar(
    star,
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			result.Set("name", star);
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				result.Set("name", star);
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
				result.Set("name", star);
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
  }

  return result;
}

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
Napi::Object node_swe_fixstar_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double x[6];
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar_ut(
    star,
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			result.Set("name", star);
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				result.Set("name", star);
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
				result.Set("name", star);
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
  }

  return result;
}

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
Napi::Object node_swe_fixstar_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double magnitude;
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar_mag(
    star,
    &magnitude,
    serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
		result.Set("name", star);
    result.Set("magnitude", magnitude);
  }

  return result;
}

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
Napi::Object node_swe_fixstar2(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double x[6];
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar2(
    star,
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			result.Set("name", star);
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				result.Set("name", star);
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
				result.Set("name", star);
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
	}

	return result;
}

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
Napi::Object node_swe_fixstar2_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString() ||
    !info[1].IsNumber() ||
    !info[2].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double x[6];
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar2_ut(
    star,
    info[1].ToNumber().DoubleValue(),
    info[2].ToNumber().Int32Value(),
    x, serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
    if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			result.Set("name", star);
      result.Set("rectAscension", x[0]);
      result.Set("declination", x[1]);
      result.Set("distance", x[2]);
      result.Set("rectAscensionSpeed", x[3]);
      result.Set("declinationSpeed", x[4]);
      result.Set("distanceSpeed", x[5]);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				result.Set("name", star);
        result.Set("x", x[0]);
        result.Set("y", x[1]);
        result.Set("z", x[2]);
        result.Set("dx", x[3]);
        result.Set("dy", x[4]);
        result.Set("dz", x[5]);
      }
      else {
				result.Set("name", star);
        result.Set("longitude", x[0]);
        result.Set("latitude", x[1]);
        result.Set("distnace", x[2]);
        result.Set("longitudeSpeed", x[3]);
        result.Set("latitudeSpeed", x[4]);
        result.Set("distanceSpeed", x[5]);
      }
    }
  }

  return result;
}

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
Napi::Object node_swe_fixstar2_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	Napi::Object result = Napi::Object::New(env);

	double magnitude;
	char star[AS_MAXCH];
  char serr[AS_MAXCH];

  long rflag;

	::strcpy(star, info[0].ToString().Utf8Value().c_str());

  rflag = ::swe_fixstar2_mag(
    star,
    &magnitude,
    serr
  );

  if (rflag < 0) {
    result.Set("error", serr);
  } else {
		result.Set("name", star);
    result.Set("magnitude", magnitude);
  }

  return result;
}

/**
 * void swe_close(void)
 * =>
 * node_swe_close: () => {}
 */
Napi::Object node_swe_close(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	::swe_close();

	return Napi::Object::New(env);
}

/**
 * void swe_set_ephe_path(char *path)
 * =>
 * node_swe_set_ephe_path: (path: string) => string
 */
Napi::String node_swe_set_ephe_path(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char path[AS_MAXCH];

	::strcpy(path, info[0].ToString().Utf8Value().c_str());

  ::swe_set_ephe_path(
    path
  );

  return Napi::String::New(env, path);
}

/**
 * void swe_set_jpl_file(char *fname)
 * =>
 * node_swe_set_jpl_file: (fname: string) => string
 */
Napi::String node_swe_set_jpl_file(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsString()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char path[AS_MAXCH];

	::strcpy(path, info[0].ToString().Utf8Value().c_str());

  ::swe_set_jpl_file(
    path
  );

  return Napi::String::New(env, path);
}

/**
 * char * swe_get_planet_name(int ipl, char *spname)
 * =>
 * node_swe_get_planet_name: (ipl: number) => string
 */
Napi::String node_swe_get_planet_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

	char name[AS_MAXCH];

  ::swe_get_planet_name(
		info[0].ToNumber().Int32Value(),
    name
  );

  return Napi::String::New(env, name);
}

/**
 * void swe_set_topo(double geolon, double geolat, double geoalt)
 * =>
 * node_swe_set_topo: (geolon: number, geolat: number, geoalt: number) => {}
 */
Napi::Object node_swe_set_topo(const Napi::CallbackInfo& info) {
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

  ::swe_set_topo(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().DoubleValue(),
		info[2].ToNumber().DoubleValue()
  );

  return Napi::Object::New(env);
}

/**
 * void swe_set_sid_mode(int32 sid_mode, double t0, double ayan_t0)
 * =>
 * node_swe_set_sid_mode: (sid_mode: number, t0: number, ayan_t0: number) => {}
 */
Napi::Object node_swe_set_sid_mode(const Napi::CallbackInfo& info) {
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

  ::swe_set_sid_mode(
		info[0].ToNumber().Int32Value(),
		info[1].ToNumber().DoubleValue(),
		info[2].ToNumber().DoubleValue()
  );

  return Napi::Object::New(env);
}

/**
 * double swe_get_ayanamsa(double tjd_et)
 * =>
 * node_swe_get_ayanamsa: (tjd_et: number) => number
 */
Napi::Number node_swe_get_ayanamsa(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

  return Napi::Number::New(env, ::swe_get_ayanamsa(
		info[0].ToNumber().DoubleValue()
  ));
}

/**
 * double swe_get_ayanamsa_ut(double tjd_ut)
 * =>
 * node_swe_get_ayanamsa_ut: (tjd_ut: number) => number
 */
Napi::Number node_swe_get_ayanamsa_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

  return Napi::Number::New(env, ::swe_get_ayanamsa_ut(
		info[0].ToNumber().DoubleValue()
  ));
}

/**
 * int32 swe_get_ayanamsa_ex(double tjd_et, int32 iflag, double *daya, char *serr)
 * =>
 * node_swe_get_ayanamsa_ex: (tjd_et: number, iflag: number) => {
 *   ayanamsa:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_get_ayanamsa_ex(const Napi::CallbackInfo& info) {
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

	double daya[1];
	char serr[AS_MAXCH];

	long val;

	val = ::swe_get_ayanamsa_ex(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		daya, serr
	);

	if (val < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("ayanamsa", daya[0]);
	}

  return result;
}

/**
 * int32 swe_get_ayanamsa_ex_ut(double tjd_ut, int32 iflag, double *daya, char *serr)
 * =>
 * node_swe_get_ayanamsa_ex_ut: (tjd_ut: number, iflag: number) => {
 *   ayanamsa:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_get_ayanamsa_ex_ut(const Napi::CallbackInfo& info) {
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

	double daya[1];
	char serr[AS_MAXCH];

	long val;

	val = ::swe_get_ayanamsa_ex_ut(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		daya, serr
	);

	if (val < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("ayanamsa", daya[0]);
	}

  return result;
}

/**
 * char * swe_get_ayanamsa_name(int32 isidmode)
 * =>
 * node_swe_get_ayanamsa_name: (isidmode: number) => string
 */
Napi::String node_swe_get_ayanamsa_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::Error::New(env, "Wrong number of arguments.").ThrowAsJavaScriptException();
  }

  if (
    !info[0].IsNumber()
  ) {
    Napi::TypeError::New(env, "Wrong type of arguments.").ThrowAsJavaScriptException();
  }

  return Napi::String::New(env, ::swe_get_ayanamsa_name(
		info[0].ToNumber().Int32Value()
  ));
}

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
Napi::Object node_swe_nod_aps(const Napi::CallbackInfo& info) {
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


	Napi::Object ascending = Napi::Object::New(env);
	Napi::Object descending = Napi::Object::New(env);
	Napi::Object perihelion = Napi::Object::New(env);
	Napi::Object aphelion = Napi::Object::New(env);

	Napi::Object result = Napi::Object::New(env);

	double xnasc[6] = {0};
	double xndsc[6] = {0};
	double xperi[6] = {0};
	double xaphe[6] = {0};
	char serr[AS_MAXCH];

	long rflag;

	rflag = ::swe_nod_aps(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		info[3].ToNumber().Int32Value(),
		xnasc, xndsc, xperi, xaphe, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			ascending.Set("rectAscension", xnasc[0]);
			ascending.Set("declination", xnasc[1]);
			ascending.Set("distance", xnasc[2]);
			ascending.Set("rectAscensionSpeed", xnasc[3]);
			ascending.Set("declinationSpeed", xnasc[4]);
			ascending.Set("distanceSpeed", xnasc[5]);
			result.Set("ascending", ascending);

			descending.Set("rectAscension", xndsc[0]);
			descending.Set("declination", xndsc[1]);
			descending.Set("distance", xndsc[2]);
			descending.Set("rectAscensionSpeed", xndsc[3]);
			descending.Set("declinationSpeed", xndsc[4]);
			descending.Set("distanceSpeed", xndsc[5]);
			result.Set("descending", descending);

			perihelion.Set("rectAscension", xperi[0]);
			perihelion.Set("declination", xperi[1]);
			perihelion.Set("distance", xperi[2]);
			perihelion.Set("rectAscensionSpeed", xperi[3]);
			perihelion.Set("declinationSpeed", xperi[4]);
			perihelion.Set("distanceSpeed", xperi[5]);
			result.Set("perihelion", perihelion);

			aphelion.Set("rectAscension", xaphe[0]);
			aphelion.Set("declination", xaphe[1]);
			aphelion.Set("distance", xaphe[2]);
			aphelion.Set("rectAscensionSpeed", xaphe[3]);
			aphelion.Set("declinationSpeed", xaphe[4]);
			aphelion.Set("distanceSpeed", xaphe[5]);
			result.Set("aphelion", aphelion);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				ascending.Set("x", xnasc[0]);
				ascending.Set("y", xnasc[1]);
				ascending.Set("z", xnasc[2]);
				ascending.Set("dx", xnasc[3]);
				ascending.Set("dy", xnasc[4]);
				ascending.Set("dz", xnasc[5]);
				result.Set("ascending", ascending);

				descending.Set("x", xndsc[0]);
				descending.Set("y", xndsc[1]);
				descending.Set("z", xndsc[2]);
				descending.Set("dx", xndsc[3]);
				descending.Set("dy", xndsc[4]);
				descending.Set("dz", xndsc[5]);
				result.Set("descending", descending);

				perihelion.Set("x", xperi[0]);
				perihelion.Set("y", xperi[1]);
				perihelion.Set("z", xperi[2]);
				perihelion.Set("dx", xperi[3]);
				perihelion.Set("dy", xperi[4]);
				perihelion.Set("dz", xperi[5]);
				result.Set("perihelion", perihelion);

				aphelion.Set("x", xaphe[0]);
				aphelion.Set("y", xaphe[1]);
				aphelion.Set("z", xaphe[2]);
				aphelion.Set("dx", xaphe[3]);
				aphelion.Set("dy", xaphe[4]);
				aphelion.Set("dz", xaphe[5]);
				result.Set("aphelion", aphelion);
      }
      else {
				ascending.Set("longitude", xnasc[0]);
				ascending.Set("latitude", xnasc[1]);
				ascending.Set("distance", xnasc[2]);
				ascending.Set("longitudeSpeed", xnasc[3]);
				ascending.Set("latitudeSpeed", xnasc[4]);
				ascending.Set("distanceSpeed", xnasc[5]);
				result.Set("ascending", ascending);

				descending.Set("longitude", xndsc[0]);
				descending.Set("latitude", xndsc[1]);
				descending.Set("distance", xndsc[2]);
				descending.Set("longitudeSpeed", xndsc[3]);
				descending.Set("latitudeSpeed", xndsc[4]);
				descending.Set("distanceSpeed", xndsc[5]);
				result.Set("descending", descending);

				perihelion.Set("longitude", xperi[0]);
				perihelion.Set("latitude", xperi[1]);
				perihelion.Set("distance", xperi[2]);
				perihelion.Set("longitudeSpeed", xperi[3]);
				perihelion.Set("latitudeSpeed", xperi[4]);
				perihelion.Set("distanceSpeed", xperi[5]);
				result.Set("perihelion", perihelion);

				aphelion.Set("longitude", xaphe[0]);
				aphelion.Set("latitude", xaphe[1]);
				aphelion.Set("distance", xaphe[2]);
				aphelion.Set("longitudeSpeed", xaphe[3]);
				aphelion.Set("latitudeSpeed", xaphe[4]);
				aphelion.Set("distanceSpeed", xaphe[5]);
				result.Set("aphelion", aphelion);
      }
    }
	}

	return result;
}

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
Napi::Object node_swe_nod_aps_ut(const Napi::CallbackInfo& info) {
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


	Napi::Object ascending = Napi::Object::New(env);
	Napi::Object descending = Napi::Object::New(env);
	Napi::Object perihelion = Napi::Object::New(env);
	Napi::Object aphelion = Napi::Object::New(env);

	Napi::Object result = Napi::Object::New(env);

	double xnasc[6] = {0};
	double xndsc[6] = {0};
	double xperi[6] = {0};
	double xaphe[6] = {0};
	char serr[AS_MAXCH];

	long rflag;

	rflag = ::swe_nod_aps_ut(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		info[3].ToNumber().Int32Value(),
		xnasc, xndsc, xperi, xaphe, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		if (info[2].ToNumber().Int32Value() & SEFLG_EQUATORIAL) {
			ascending.Set("rectAscension", xnasc[0]);
			ascending.Set("declination", xnasc[1]);
			ascending.Set("distance", xnasc[2]);
			ascending.Set("rectAscensionSpeed", xnasc[3]);
			ascending.Set("declinationSpeed", xnasc[4]);
			ascending.Set("distanceSpeed", xnasc[5]);
			result.Set("ascending", ascending);

			descending.Set("rectAscension", xndsc[0]);
			descending.Set("declination", xndsc[1]);
			descending.Set("distance", xndsc[2]);
			descending.Set("rectAscensionSpeed", xndsc[3]);
			descending.Set("declinationSpeed", xndsc[4]);
			descending.Set("distanceSpeed", xndsc[5]);
			result.Set("descending", descending);

			perihelion.Set("rectAscension", xperi[0]);
			perihelion.Set("declination", xperi[1]);
			perihelion.Set("distance", xperi[2]);
			perihelion.Set("rectAscensionSpeed", xperi[3]);
			perihelion.Set("declinationSpeed", xperi[4]);
			perihelion.Set("distanceSpeed", xperi[5]);
			result.Set("perihelion", perihelion);

			aphelion.Set("rectAscension", xaphe[0]);
			aphelion.Set("declination", xaphe[1]);
			aphelion.Set("distance", xaphe[2]);
			aphelion.Set("rectAscensionSpeed", xaphe[3]);
			aphelion.Set("declinationSpeed", xaphe[4]);
			aphelion.Set("distanceSpeed", xaphe[5]);
			result.Set("aphelion", aphelion);
    }
    else {
      if (info[2].ToNumber().Int32Value() & SEFLG_XYZ) {
				ascending.Set("x", xnasc[0]);
				ascending.Set("y", xnasc[1]);
				ascending.Set("z", xnasc[2]);
				ascending.Set("dx", xnasc[3]);
				ascending.Set("dy", xnasc[4]);
				ascending.Set("dz", xnasc[5]);
				result.Set("ascending", ascending);

				descending.Set("x", xndsc[0]);
				descending.Set("y", xndsc[1]);
				descending.Set("z", xndsc[2]);
				descending.Set("dx", xndsc[3]);
				descending.Set("dy", xndsc[4]);
				descending.Set("dz", xndsc[5]);
				result.Set("descending", descending);

				perihelion.Set("x", xperi[0]);
				perihelion.Set("y", xperi[1]);
				perihelion.Set("z", xperi[2]);
				perihelion.Set("dx", xperi[3]);
				perihelion.Set("dy", xperi[4]);
				perihelion.Set("dz", xperi[5]);
				result.Set("perihelion", perihelion);

				aphelion.Set("x", xaphe[0]);
				aphelion.Set("y", xaphe[1]);
				aphelion.Set("z", xaphe[2]);
				aphelion.Set("dx", xaphe[3]);
				aphelion.Set("dy", xaphe[4]);
				aphelion.Set("dz", xaphe[5]);
				result.Set("aphelion", aphelion);
      }
      else {
				ascending.Set("longitude", xnasc[0]);
				ascending.Set("latitude", xnasc[1]);
				ascending.Set("distance", xnasc[2]);
				ascending.Set("longitudeSpeed", xnasc[3]);
				ascending.Set("latitudeSpeed", xnasc[4]);
				ascending.Set("distanceSpeed", xnasc[5]);
				result.Set("ascending", ascending);

				descending.Set("longitude", xndsc[0]);
				descending.Set("latitude", xndsc[1]);
				descending.Set("distance", xndsc[2]);
				descending.Set("longitudeSpeed", xndsc[3]);
				descending.Set("latitudeSpeed", xndsc[4]);
				descending.Set("distanceSpeed", xndsc[5]);
				result.Set("descending", descending);

				perihelion.Set("longitude", xperi[0]);
				perihelion.Set("latitude", xperi[1]);
				perihelion.Set("distance", xperi[2]);
				perihelion.Set("longitudeSpeed", xperi[3]);
				perihelion.Set("latitudeSpeed", xperi[4]);
				perihelion.Set("distanceSpeed", xperi[5]);
				result.Set("perihelion", perihelion);

				aphelion.Set("longitude", xaphe[0]);
				aphelion.Set("latitude", xaphe[1]);
				aphelion.Set("distance", xaphe[2]);
				aphelion.Set("longitudeSpeed", xaphe[3]);
				aphelion.Set("latitudeSpeed", xaphe[4]);
				aphelion.Set("distanceSpeed", xaphe[5]);
				result.Set("aphelion", aphelion);
      }
    }
	}

	return result;
}

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
Napi::Object node_swe_get_orbital_elements(const Napi::CallbackInfo& info) {
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

	double dret[50];
	char serr[AS_MAXCH];

	long rflag;

	rflag = ::swe_get_orbital_elements(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		dret, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("semimajorAxis", dret[0]);
		result.Set("eccentricity", dret[1]);
		result.Set("inclination", dret[2]);
		result.Set("ascendingNode", dret[3]);
		result.Set("periapsisArg", dret[4]);
		result.Set("periapsis", dret[5]);
		result.Set("meanAnomaly", dret[6]);
		result.Set("trueAnomaly", dret[7]);
		result.Set("eccentricAnomaly", dret[8]);
		result.Set("meanLongitude", dret[9]);
		result.Set("siderealPeriod", dret[10]);
		result.Set("meanDailyMotion", dret[11]);
		result.Set("tropicalPeriod", dret[12]);
		result.Set("synodicPeriod", dret[13]);
		result.Set("perihelionPassage", dret[14]);
		result.Set("perihelionDistance", dret[15]);
		result.Set("aphelionDistance", dret[16]);
	}

	return result;
}

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
Napi::Object node_swe_orbit_max_min_true_distance(const Napi::CallbackInfo& info) {
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

	double dmax[1];
	double dmin[1];
	double dtrue[1];
	char serr[AS_MAXCH];

	long rflag;

	rflag = ::swe_orbit_max_min_true_distance(
		info[0].ToNumber().DoubleValue(),
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		dmax, dmin, dtrue, serr
	);

	if (rflag < 0) {
		result.Set("error", serr);
	}
	else {
		result.Set("maxDistance", dmax[0]);
		result.Set("minDistance", dmin[0]);
		result.Set("trueDistance", dtrue[0]);
	}

	return result;
}