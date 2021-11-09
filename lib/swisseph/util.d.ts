/* eslint-disable camelcase */

declare namespace Util {
  /**
   * Computes the difference between Universal Time (UT, GMT) and Ephemeris time.
   * @param tjd The Julian day.
   * @returns The result of the computation.
   */
  export function node_swe_deltat(tjd: number): number;

  /**
   * Returns the difference between local apparent and local mean time.
   * @param tjd The Julian day.
   * @returns The result of the computation or an error.
   */
  export function node_swe_time_equ(
    tjd: number
  ): { timeEquation: number } | { error: string };

  /**
   * Returns sidereal time for a Julian day, obliquity and nutation.
   * @param tjd_ut The Julian day.
   * @param eps The obliquity.
   * @param nut The nutation.
   * @returns Sidereal time at the Greenwich Meridian, measured in hours.
   */
  export function node_swe_sidtime0(
    tjd_ut: number,
    eps: number,
    nut: number
  ): number;

  /**
   * Returns sidereal time for a Julian day. Computes obliquity and nutation internally.
   * @param tjd_ut The Julian day.
   * @returns Sidereal time at the Greenwich Meridian, measured in hours.
   */
  export function node_swe_sidtime(tjd_ut: number): number;

  /**
   * Coordinate transformation, from ecliptic to equator or vice-versa.
   * - equator -> ecliptic: eps must be positive
   * - ecliptic -> equator: eps must be negative
   * Note: eps, longitude and latitude are in positive degrees!
   * @param xpo 3 doubles: long., lat., dist. to be converted; distance remains unchanged, can be set to 1.00.
   * @param eps Obliquity of ecliptic, in degrees.
   * @returns Result of the conversion. 3 doubles: long., lat., dist.
   */
  export function node_swe_cotrans(
    xpo: number[],
    eps: number
  ): {
    longitude: number;
    latitude: number;
    distance: number;
  };

  /**
   * Coordinate transformation of position and speed, from ecliptic to equator or vice-versa.
   * - equator -> ecliptic: eps must be positive
   * - ecliptic -> equator: eps must be negative
   * Note: eps, long., lat., and speeds in long. and lat. are in degrees!
   * @param xpo 6 doubles, input: long., lat., dist. and speeds in long., lat and dist.
   * @param eps Obliquity of ecliptic, in degrees.
   * @returns Result of the conversion. 6 doubles, position and speed in new coordinate system.
   */
  export function node_swe_cotrans_sp(
    xpo: number[],
    eps: number
  ): {
    longitude: number;
    latitude: number;
    distance: number;
    longitudeSpeed: number;
    latitudeSpeed: number;
    distanceSpeed: number;
  };

  /**
   * Returns the tidal acceleration used in node_swe_deltat().
   * @returns The tidal acceleration.
   */
  export function node_swe_get_tid_acc(): number;

  /**
   * Sets the tidal acceleration to be used in node_swe_deltat().
   * @param t_acc The tidal acceleration.
   * @returns An empty object.
   */
  export function node_swe_set_tid_acc(t_acc: number): {};

  /**
   * Normalizes a degree to the range 0 - 360.
   * @param x The degree to normalize.
   * @returns The result of the normalization.
   */
  export function node_swe_degnorm(x: number): number;

  /**
   * Normalizes a radian to the range 0 - 2 PI.
   * @param x The radian to normalize.
   * @returns The result of the normalization.
   */
  export function node_swe_radnorm(x: number): number;

  /**
   * Return the mid point between two radians.
   * @param x1 The first radian.
   * @param x0 The second radian.
   * @returns The result of the computation.
   */
  export function node_swe_rad_midp(x1: number, x0: number): number;

  /**
   * Return the mid point between two degrees.
   * @param x1 The first degree.
   * @param x0 The second degree.
   * @returns The result of the computation.
   */
  export function node_swe_deg_midp(x1: number, x0: number): number;

  /**
   * Split degrees to sign/nakshatra, degrees, minutes, seconds of arc.
   * @param ddeg Decimal degrees, ecliptic longitude.
   * @param roundflag By default there is no rounding. If rounding is required, the following bits can be set:
   *                  SE_SPLIT_DEG_ROUND_SEC, SE_SPLIT_DEG_ROUND_MIN, SE_SPLIT_DEG_ROUND_DEG,
   *                  SE_SPLIT_DEG_ZODIACAL, SE_SPLIT_DEG_KEEP_SIGN and SE_SPLIT_DEG_NAKSHATRA.
   * @returns The result of the splitting.
   *          (degree = degree integer, min = degree minutes, second = degree seconds,
   *           secondFraction = degree fraction of seconds, sign = zodiac sign number)
   */
  export function node_swe_split_deg(
    ddeg: number,
    roundflag: number
  ): {
    degree: number;
    min: number;
    second: number;
    secondFraction: number;
    sign: number;
  };

  /**
   * Normalize a centisecond value into the interval 0 - 360 DEG.
   * @param p The centisecond value.
   * @returns The result of the computation.
   */
  export function node_swe_csnorm(p: number): number;

  /**
   * Distance in centisecs between p1 and p2 normalized to 0 - 360.
   * @param p1 The first centisecond value
   * @param p2 The second centisecond value
   * @returns The result of the computation.
   */
  export function node_swe_difcsn(p1: number, p2: number): number;

  /**
   * Distance in degrees between p1 and p2.
   * @param p1 The first degree value.
   * @param p2 The second degree value.
   * @returns The result of the computation.
   */
  export function node_swe_difdegn(p1: number, p2: number): number;

  /**
   * Distance in centisecs between p1 and p2 normalized to -180 - 180.
   * @param p1 The first centisecond value
   * @param p2 The second centisecond value
   * @returns The result of the computation.
   */
  export function node_swe_difcs2n(p1: number, p2: number): number;

  /**
   * Distance in degrees between p1 and p2 normalized to -180 - 180.
   * @param p1 The first degree value.
   * @param p2 The second degree value.
   * @returns The result of the computation.
   */
  export function node_swe_difdeg2n(p1: number, p2: number): number;

  /**
   * Distance in radians between p1 and p2 normalized to -PI - PI.
   * @param p1 The first radian value.
   * @param p2 The second radian value.
   * @returns The result of the computation.
   */
  export function node_swe_difrad2n(p1: number, p2: number): number;

  /**
   * Round centisecond value, but at 29.5959 always down.
   * @param x The centisecond value to round.
   * @returns The result of the computation.
   */
  export function node_swe_csroundsec(x: number): number;

  /**
   * Convert double to long with rounding, no overflow check.
   * @param x The double value to convert.
   * @returns The result of the conversion.
   */
  export function node_swe_d2l(x: number): number;

  /**
   * Returns the day of week for a Julian day.
   * @param jd The Julian day.
   * @returns Monday = 0, ... Sunday = 6.
   */
  export function node_swe_day_of_week(jd: number): number;

  /**
   * Converts a centisecond value to a time string.
   * @param t The centisecond value.
   * @param sep Separator value.
   * @param suppressZero Specifies whether to suppress zero values. (0 = no, 1 = yes)
   * @returns The result of the conversion.
   */
  export function node_swe_cs2timestr(
    t: number,
    sep: number,
    suppressZero: number
  ): string;

  /**
   * Converts a centisecond value to a longitude or latitude string.
   * @param t The centisecond value.
   * @param pchar Character used for positive values.
   * @param mchar Character used for negative values.
   * @returns The result of the conversion.
   */
  export function node_swe_cs2lonlatstr(
    t: number,
    pchar: string,
    mchar: string
  ): string;

  /**
   * Converts a centisecond value to a degree string.
   * @param t The centisecond value.
   * @returns The result of the conversion.
   */
  export function node_swe_cs2degstr(t: number): string;
}

export = Util;
