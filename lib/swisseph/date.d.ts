/* eslint-disable camelcase */

import { SE_GREG_CAL, SE_JUL_CAL } from "./constant";

declare namespace Date {
  /**
   * Conversion from day, month, year, time to Julian day with error handling.
   * @param year The year of the date.
   * @param month The month of the date.
   * @param day The day of the date.
   * @param hour The hour of the date.
   * @param gregflag Specifies whether the input date is Julian calendar ('j') or Gregorian calendar ('g').
   * @returns The result of the conversion or an error.
   */
  export function node_swe_date_conversion(
    year: number,
    month: number,
    day: number,
    hour: number,
    gregflag: "g" | "j"
  ): { julianDay: number } | { error: string };

  /**
   * Conversion from day, month, year, time to Julian day.
   * @param year The year of the date.
   * @param month The month of the date.
   * @param day The day of the date.
   * @param hour The hour of the date.
   * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
   * @returns The result of the conversion.
   */
  export function node_swe_julday(
    year: number,
    month: number,
    day: number,
    hour: number,
    gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL
  ): number;

  /**
   * Reverse conversion of a Julian day value to a date object.
   * @param jd The Julian day.
   * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
   * @returns The result of the conversion.
   */
  export function node_swe_revjul(
    jd: number,
    gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL
  ): {
    year: number;
    month: number;
    day: number;
    hour: number;
  };

  /**
   * Conversion from day, month, year, time in Coordinated Universal Time (UTC) to Julian day.
   * @param iyear The year of the date.
   * @param imonth The month of the date.
   * @param iday The day of the date.
   * @param ihour The hour of the date.
   * @param imin The minute of the date.
   * @param dsec The second of the date.
   * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
   * @returns The result of the conversion or an error.
   */
  export function node_swe_utc_to_jd(
    iyear: number,
    imonth: number,
    iday: number,
    ihour: number,
    imin: number,
    dsec: number,
    gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL
  ):
    | {
        julianDayET: number;
        julianDayUT: number;
      }
    | { error: string };

  /**
   * Reverse conversion of a Julian day value to a date object in Coordinated Universal Time (UTC).
   * @param tjd_et The Julian day number in ET (TT).
   * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
   * @returns The result of the conversion.
   */
  export function node_swe_jdet_to_utc(
    tjd_et: number,
    gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL
  ): {
    year: number;
    month: number;
    day: number;
    hour: number;
    minute: number;
    second: number;
  };

  /**
   * Reverse conversion of a Julian day value to a date object in Coordinated Universal Time (UTC).
   * @param tjd_ut The Julian day number in UT (UT1).
   * @param gregflag Specifies whether the input date is Julian calendar (SE_JUL_CAL) or Gregorian calendar (SE_GREG_CAL).
   * @returns The result of the conversion.
   */
  export function node_swe_jdut1_to_utc(
    tjd_ut: number,
    gregflag: typeof SE_JUL_CAL | typeof SE_GREG_CAL
  ): {
    year: number;
    month: number;
    day: number;
    hour: number;
    minute: number;
    second: number;
  };

  /**
   * Converts a UTC date value to a local date value using the specified time zone offset.
   * @param iyear The year of the date.
   * @param imonth The month of the date.
   * @param iday The day of the date.
   * @param ihour The hour of the date.
   * @param imin The minute of the date.
   * @param dsec The second of the date.
   * @param d_timezone The time zone offset.
   * @returns The result of the conversion.
   */
  export function node_swe_utc_time_zone(
    iyear: number,
    imonth: number,
    iday: number,
    ihour: number,
    imin: number,
    dsec: number,
    d_timezone: number
  ): {
    year: number;
    month: number;
    day: number;
    hour: number;
    minute: number;
    second: number;
  };
}

export = Date;
