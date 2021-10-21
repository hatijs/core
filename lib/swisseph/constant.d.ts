declare namespace Constant {
  export const SE_AUNIT_TO_KM = 149597870.7;
  export const SE_AUNIT_TO_LIGHTYEAR = 0.000015812507409819728; // 1.5812507409819728411242766893179e-5; // = 1.0 / 63241.07708427
  export const SE_AUNIT_TO_PARSEC = 0.000004848136811095274; // 4.8481368110952742659276431719005e-6; // = 1.0 / 206264.8062471

  export const SE_MAX_STNAME = 256;

  export const SE_SIDBITS = 256;
  export const SE_SIDBIT_ECL_T0 = 256;
  export const SE_SIDBIT_SSY_PLANE = 512;
  export const SE_SIDBIT_USER_UT = 1024;

  export const SE_BIT_DISC_CENTER = 256;
  export const SE_BIT_DISC_BOTTOM = 8192;
  export const SE_BIT_GEOCTR_NO_ECL_LAT = 128;
  export const SE_BIT_NO_REFRACTION = 512;
  export const SE_BIT_CIVIL_TWILIGHT = 1024;
  export const SE_BIT_NAUTIC_TWILIGHT = 2048;
  export const SE_BIT_ASTRO_TWILIGHT = 4096;
  export const SE_BIT_FIXED_DISC_SIZE = 16384; // = 16 * 1024

  export const TJD_INVALID = 99999999.0;
  export const SIMULATE_VICTORVB = 1;

  export const SE_PHOTOPIC_FLAG = 0;
  export const SE_SCOTOPIC_FLAG = 1;
  export const SE_MIXEDOPIC_FLAG = 2;

  export const ephemeris: {
    swisseph: 2; // = SEFLG_SWIEPH
    moshier: 4; // = SEFLG_MOSEPH
    de200: "de200.eph";
    de405: "de405.eph";
    de406: "de406.eph";
    de406e: "de406e.eph";
    de414: "de414.eph";
    de421: "de421.eph";
    de422: "de422.eph";
    de430: "de430.eph";
    de431: "de431.eph";
  };

  // Calendar types
  export const SE_JUL_CAL = 0;
  export const SE_GREG_CAL = 1;

  // Planet numbers
  export const SE_SUN = 0;
  export const SE_MOON = 1;
  export const SE_MERCURY = 2;
  export const SE_VENUS = 3;
  export const SE_EARTH = 14;
  export const SE_MARS = 4;
  export const SE_JUPITER = 5;
  export const SE_SATURN = 6;
  export const SE_URANUS = 7;
  export const SE_NEPTUNE = 8;
  export const SE_PLUTO = 9;

  // Moon nodes
  export const SE_MEAN_NODE = 10;
  export const SE_TRUE_NODE = 11;
  export const SE_MEAN_APOG = 12;
  export const SE_OSCU_APOG = 13;
  export const SE_INTP_APOG = 21;
  export const SE_INTP_PERG = 22;

  // Base asteroids
  export const SE_CHIRON = 15;
  export const SE_PHOLUS = 16;
  export const SE_CERES = 17;
  export const SE_PALLAS = 18;
  export const SE_JUNO = 19;
  export const SE_VESTA = 20;

  export const SE_NPLANETS = 23;
  export const SE_AST_OFFSET = 10000;
  export const SE_VARUNA = 30000; // = SE_AST_OFFSET + 20000
  export const SE_FICT_OFFSET = 40;
  export const SE_FICT_OFFSET_1 = 39;
  export const SE_FICT_MAX = 999;
  export const SE_NFICT_ELEM = 15;
  export const SE_COMET_OFFSET = 1000;
  export const SE_NALL_NAT_POINTS = 38; // = SE_NPLANETS + SE_NFICT_ELEM

  // Hamburger or Uranian "planets"
  export const SE_CUPIDO = 40;
  export const SE_HADES = 41;
  export const SE_ZEUS = 42;
  export const SE_KRONOS = 43;
  export const SE_APOLLON = 44;
  export const SE_ADMETOS = 45;
  export const SE_VULKANUS = 46;
  export const SE_POSEIDON = 47;

  // Other fictitious bodies
  export const SE_ISIS = 48;
  export const SE_NIBIRU = 49;
  export const SE_HARRINGTON = 50;
  export const SE_NEPTUNE_LEVERRIER = 51;
  export const SE_NEPTUNE_ADAMS = 52;
  export const SE_PLUTO_LOWELL = 53;
  export const SE_PLUTO_PICKERING = 54;
  export const SE_VULCAN = 55;
  export const SE_WHITE_MOON = 56;
  export const SE_PROSERPINA = 57;
  export const SE_WALDEMATH = 58;

  export const SE_FIXSTAR = -10;
  export const SE_ASC = 0;
  export const SE_MC = 1;
  export const SE_ARMC = 2;
  export const SE_VERTEX = 3;
  export const SE_EQUASC = 4;
  export const SE_COASC1 = 5;
  export const SE_COASC2 = 6;
  export const SE_POLASC = 7;
  export const SE_NASCMC = 8;

  // Flag bits for "iflag" parameter of the "swe_calc" functions
  export const SEFLG_JPLEPH = 1;
  export const SEFLG_SWIEPH = 2;
  export const SEFLG_MOSEPH = 4;
  export const SEFLG_HELCTR = 8;
  export const SEFLG_TRUEPOS = 16;
  export const SEFLG_J2000 = 32;
  export const SEFLG_NONUT = 64;
  export const SEFLG_SPEED3 = 128;
  export const SEFLG_SPEED = 256;
  export const SEFLG_NOGDEFL = 512;
  export const SEFLG_NOABERR = 1024;
  export const SEFLG_ASTROMETRIC = 1536; // = SEFLG_NOABERR | SEFLG_NOGDEFL
  export const SEFLG_EQUATORIAL = 2048; // = 2  *1024
  export const SEFLG_XYZ = 4096; // = 4 * 1024
  export const SEFLG_RADIANS = 8192; // = 8 * 1024
  export const SEFLG_BARYCTR = 16384; // = 16 * 1024
  export const SEFLG_TOPOCTR = 32768; // = 32 * 1024
  export const SEFLG_ORBEL_AA = 32768; // = SEFLG_TOPOCTR
  export const SEFLG_SIDEREAL = 65536; // = 64 * 1024
  export const SEFLG_ICRS = 131072; // = 128 * 1024
  export const SEFLG_DPSIDEPS_1980 = 262144; // = 256*1024
  export const SEFLG_JPLHOR = 262144; // = SEFLG_DPSIDEPS_1980
  export const SEFLG_JPLHOR_APPROX = 524288; // = 512*1024
  export const SEFLG_DEFAULTEPH = 2; // = SEFLG_SWIEPH

  // Sidereal modes
  export const SE_SIDM_FAGAN_BRADLEY = 0;
  export const SE_SIDM_LAHIRI = 1;
  export const SE_SIDM_DELUCE = 2;
  export const SE_SIDM_RAMAN = 3;
  export const SE_SIDM_USHASHASHI = 4;
  export const SE_SIDM_KRISHNAMURTI = 5;
  export const SE_SIDM_DJWHAL_KHUL = 6;
  export const SE_SIDM_YUKTESHWAR = 7;
  export const SE_SIDM_JN_BHASIN = 8;
  export const SE_SIDM_BABYL_KUGLER1 = 9;
  export const SE_SIDM_BABYL_KUGLER2 = 10;
  export const SE_SIDM_BABYL_KUGLER3 = 11;
  export const SE_SIDM_BABYL_HUBER = 12;
  export const SE_SIDM_BABYL_ETPSC = 13;
  export const SE_SIDM_ALDEBARAN_15TAU = 14;
  export const SE_SIDM_HIPPARCHOS = 15;
  export const SE_SIDM_SASSANIAN = 16;
  export const SE_SIDM_GALCENT_0SAG = 17;
  export const SE_SIDM_J2000 = 18;
  export const SE_SIDM_J1900 = 19;
  export const SE_SIDM_B1950 = 20;
  export const SE_SIDM_SURYASIDDHANTA = 21;
  export const SE_SIDM_SURYASIDDHANTA_MSUN = 22;
  export const SE_SIDM_ARYABHATA = 23;
  export const SE_SIDM_ARYABHATA_MSUN = 24;
  export const SE_SIDM_SS_REVATI = 25;
  export const SE_SIDM_SS_CITRA = 26;
  export const SE_SIDM_TRUE_CITRA = 27;
  export const SE_SIDM_TRUE_REVATI = 28;
  export const SE_SIDM_TRUE_PUSHYA = 29;
  export const SE_SIDM_GALCENT_RGILBRAND = 30;
  export const SE_SIDM_GALEQU_IAU1958 = 31;
  export const SE_SIDM_GALEQU_TRUE = 32;
  export const SE_SIDM_GALEQU_MULA = 33;
  export const SE_SIDM_GALALIGN_MARDYKS = 34;
  export const SE_SIDM_TRUE_MULA = 35;
  export const SE_SIDM_GALCENT_MULA_WILHELM = 36;
  export const SE_SIDM_ARYABHATA_522 = 37;
  export const SE_SIDM_BABYL_BRITTON = 38;
  export const SE_SIDM_TRUE_SHEORAN = 39;
  export const SE_SIDM_GALCENT_COCHRANE = 40;
  export const SE_SIDM_GALEQU_FIORENZA = 41;
  export const SE_SIDM_VALENS_MOON = 42;
  export const SE_SIDM_USER = 255;
  export const SE_NSIDM_PREDEF = 43;

  // Used for "swe_nod_aps" function
  export const SE_NODBIT_MEAN = 1;
  export const SE_NODBIT_OSCU = 2;
  export const SE_NODBIT_OSCU_BAR = 4;
  export const SE_NODBIT_FOPOINT = 256;

  // Used for eclipse computations
  export const SE_ECL_NUT = -1;
  export const SE_ECL_CENTRAL = 1;
  export const SE_ECL_NONCENTRAL = 2;
  export const SE_ECL_TOTAL = 4;
  export const SE_ECL_ANNULAR = 8;
  export const SE_ECL_PARTIAL = 16;
  export const SE_ECL_ANNULAR_TOTAL = 32;
  export const SE_ECL_PENUMBRAL = 64;
  export const SE_ECL_ALLTYPES_SOLAR = 63; // = SE_ECL_CENTRAL | SE_ECL_NONCENTRAL | SE_ECL_TOTAL | SE_ECL_ANNULAR | SE_ECL_PARTIAL | SE_ECL_ANNULAR_TOTAL
  export const SE_ECL_ALLTYPES_LUNAR = 84; // = SE_ECL_TOTAL | SE_ECL_PARTIAL | SE_ECL_PENUMBRAL
  export const SE_ECL_VISIBLE = 128;
  export const SE_ECL_MAX_VISIBLE = 256;
  export const SE_ECL_1ST_VISIBLE = 512;
  export const SE_ECL_PARTBEG_VISIBLE = 512;
  export const SE_ECL_2ND_VISIBLE = 1024;
  export const SE_ECL_TOTBEG_VISIBLE = 1024;
  export const SE_ECL_3RD_VISIBLE = 2048;
  export const SE_ECL_TOTEND_VISIBLE = 2048;
  export const SE_ECL_4TH_VISIBLE = 4096;
  export const SE_ECL_PARTEND_VISIBLE = 4096;
  export const SE_ECL_PENUMBBEG_VISIBLE = 8192;
  export const SE_ECL_PENUMBEND_VISIBLE = 16384;
  export const SE_ECL_OCC_BEG_DAYLIGHT = 8192;
  export const SE_ECL_OCC_END_DAYLIGHT = 16384;
  export const SE_ECL_ONE_TRY = 32768; // = 32 * 1024

  // Used for "swe_rise_transit"
  export const SE_CALC_RISE = 1;
  export const SE_CALC_SET = 2;
  export const SE_CALC_MTRANSIT = 4;
  export const SE_CALC_ITRANSIT = 8;

  // Used for "swe_azalt" and "swe_azalt_rev" functions
  export const SE_ECL2HOR = 0;
  export const SE_EQU2HOR = 1;
  export const SE_HOR2ECL = 0;
  export const SE_HOR2EQU = 1;

  // Used for "swe_refrac" function
  export const SE_TRUE_TO_APP = 0;
  export const SE_APP_TO_TRUE = 1;

  // Rounding flags for "swe_split_deg" function
  export const SE_SPLIT_DEG_ROUND_SEC = 1;
  export const SE_SPLIT_DEG_ROUND_MIN = 2;
  export const SE_SPLIT_DEG_ROUND_DEG = 4;
  export const SE_SPLIT_DEG_ZODIACAL = 8;
  export const SE_SPLIT_DEG_KEEP_SIGN = 16;
  export const SE_SPLIT_DEG_KEEP_DEG = 32;
  export const SE_SPLIT_DEG_NAKSHATRA = 1024;

  // Used for heliacal functions
  export const SE_HELIACAL_RISING = 1;
  export const SE_HELIACAL_SETTING = 2;
  export const SE_MORNING_FIRST = 1; // = SE_HELIACAL_RISING
  export const SE_EVENING_LAST = 2; // = SE_HELIACAL_SETTING
  export const SE_EVENING_FIRST = 3;
  export const SE_MORNING_LAST = 4;
  export const SE_ACRONYCHAL_RISING = 5;
  export const SE_ACRONYCHAL_SETTING = 6;
  export const SE_COSMICAL_SETTING = 6; // = SE_ACRONYCHAL_SETTING

  export const SE_HELFLAG_LONG_SEARCH = 128;
  export const SE_HELFLAG_HIGH_PRECISION = 256;
  export const SE_HELFLAG_OPTICAL_PARAMS = 512;
  export const SE_HELFLAG_NO_DETAILS = 1024;
  export const SE_HELFLAG_SEARCH_1_PERIOD = 2048; // = 1 << 11
  export const SE_HELFLAG_VISLIM_DARK = 4096; // = 1 << 12
  export const SE_HELFLAG_VISLIM_NOMOON = 8192; // = 1 << 13
  export const SE_HELFLAG_VISLIM_PHOTOPIC = 16384; // = 1 << 14
  export const SE_HELFLAG_AVKIND_VR = 32768; // = 1 << 15
  export const SE_HELFLAG_AVKIND_PTO = 65536; // = 1 << 16
  export const SE_HELFLAG_AVKIND_MIN7 = 131072; // = 1 << 17
  export const SE_HELFLAG_AVKIND_MIN9 = 262144; // = 1 << 18
  export const SE_HELFLAG_AVKIND = 491520; // = SE_HELFLAG_AVKIND_VR | SE_HELFLAG_AVKIND_PTO | SE_HELFLAG_AVKIND_MIN7 | SE_HELFLAG_AVKIND_MIN9
}

export = Constant;
