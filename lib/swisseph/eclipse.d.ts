/* eslint-disable camelcase */

import {
  SE_TRUE_TO_APP,
  SE_APP_TO_TRUE,
  SE_ECL2HOR,
  SE_EQU2HOR,
  SE_HOR2ECL,
  SE_HOR2EQU,
} from "./constant";

declare namespace House {
  /**
   * Calculates the Gauquelin sector position of a planet.
   * @param t_ut The Julian day in Universal Time.
   * @param ipl The planet number, if planet, or moon. This value is ignored if the parameter "starname" is set.
   * @param starname The star name, if star.
   * @param iflag Flag for ephemeris and SEFLG_TOPOCTR.
   * @param imeth The calculation method used. Possible values: 0 to 5.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height of the observer.
   * @param atpress The atmospheric pressure. Only useful with imeth = 3.
   * @param attemp The atmospheric temperature in degrees Celsius. Only useful with imeth = 3.
   * @returns The result of the computation or an error.
   */
  export function node_swe_gauquelin_sector(
    t_ut: number,
    ipl: number,
    starname: string,
    iflag: number,
    imeth: number,
    longitude: number,
    latitude: number,
    height: number,
    atpress: number,
    attemp: number
  ):
    | {
        name: string;
        gauquelinSector: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the geographic position where an eclipse is central or maximal.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @returns The result of the computation or an error.
   */
  export function node_swe_sol_eclipse_where(
    tjd_ut: number,
    ifl: number
  ):
    | {
        rflag: number;
        longitude: number;
        latitude: number;
        solarDiameterFraction: number;
        lonarToSolarDiameterRatio: number;
        solarDiscFraction: number;
        coreShadow: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonToSunAngularDistance: number;
        eclipseMagnitude: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the geographic position, where, for a given time, a central eclipse is central or
   * where a non-central eclipse is maximal.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ipl The planet number.
   * @param starname The star name. Must be null or "" if not a star.
   * @param ifl The ephemeris flag.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_occult_where(
    tjd_ut: number,
    ipl: number,
    starname: string,
    ifl: number
  ):
    | {
        rflag: number;
        longitude: number;
        latitude: number;
        solarDiameterFraction: number;
        lonarToSolarDiameterRatio: number;
        solarDiscFraction: number;
        coreShadow: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonToSunAngularDistance: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the solar eclipse attributes for a given geographic position and time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @returns The result of the computation or an error.
   */
  export function node_swe_sol_eclipse_how(
    tjd_ut: number,
    ifl: number,
    longitude: number,
    latitude: number,
    height: number
  ):
    | {
        rflag: number;
        solarDiameterFraction: number;
        lonarToSolarDiameterRatio: number;
        solarDiscFraction: number;
        coreShadow: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonToSunAngularDistance: number;
        eclipseMagnitude: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next solar eclipse for a given geographic position.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @param backward 1 for backward search, 0 otherwise.
   * @returns The result of the computation or an error.
   */
  export function node_swe_sol_eclipse_when_loc(
    tjd_start: number,
    ifl: number,
    longitude: number,
    latitude: number,
    height: number,
    backward: 0 | 1
  ):
    | {
        rflag: number;
        maximum: number;
        first: number;
        second: number;
        third: number;
        forth: number;
        solarDiameterFraction: number;
        lonarToSolarDiameterRatio: number;
        solarDiscFraction: number;
        coreShadow: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonToSunAngularDistance: number;
        eclipseMagnitude: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next occultation of a planet or star by the moon for a given location.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ipl The planet number of the occulted body.
   * @param starname The name of the occulted star. Must be null or "" if a planetary occultation is calculated.
   * @param ifl The ephemeris flag.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @param backward 1 for backward search, 0 otherwise.
   *                 Set flag SE_ECL_ONE_TRY to prevent infinite loops for impossible events.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_occult_when_loc(
    tjd_start: number,
    ipl: number,
    starname: string,
    ifl: number,
    longitude: number,
    latitude: number,
    height: number,
    backward: number
  ):
    | {
        rflag: number;
        name: string;
        maximum: number;
        first: number;
        second: number;
        third: number;
        forth: number;
        solarDiameterFraction: number;
        lonarToSolarDiameterRatio: number;
        solarDiscFraction: number;
        coreShadow: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonToSunAngularDistance: number;
        eclipseMagnitude: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next solar eclipse globally.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
   * @param backward 1 for backward search, 0 otherwise.
   * @returns The result of the computation or an error.
   */
  export function node_swe_sol_eclipse_when_glob(
    tjd_start: number,
    ifl: number,
    ifltype: number,
    backward: 0 | 1
  ):
    | {
        rflag: number;
        maximum: number;
        noon: number;
        begin: number;
        end: number;
        totalBegin: number;
        totalEnd: number;
        centerBegin: number;
        centerEnd: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next occultation of a planet or star by the moon globally.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ipl The planet number of the occulted body.
   * @param starname The name of the occulted star. Must be null or "" if a planetary occultation is calculated.
   * @param ifl The ephemeris flag.
   * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
   * @param backward 1 for backward search, 0 otherwise.
   *                 Set flag SE_ECL_ONE_TRY to prevent infinite loops for impossible events.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_occult_when_glob(
    tjd_start: number,
    ipl: number,
    starname: string,
    ifl: number,
    ifltype: number,
    backward: number
  ):
    | {
        rflag: number;
        name: string;
        maximum: number;
        noon: number;
        begin: number;
        end: number;
        totalBegin: number;
        totalEnd: number;
        centerBegin: number;
        centerEnd: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the attributes of a lunar eclipse for a given time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_eclipse_how(
    tjd_ut: number,
    ifl: number,
    longitude: number,
    latitude: number,
    height: number
  ):
    | {
        rflag: number;
        umbralMagnitude: number;
        penumbralMagnitude: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        oppositeDegreeDistance: number;
        magnitude: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next lunar eclipse globally.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param ifltype Flags for the wanted eclipse type. (e.g. SE_ECL_TOTAL)
   * @param backward 1 for backward search, 0 otherwise.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_eclipse_when(
    tjd_start: number,
    ifl: number,
    ifltype: number,
    backward: 0 | 1
  ):
    | {
        rflag: number;
        maximum: number;
        partialBegin: number;
        partialEnd: number;
        totalBegin: number;
        totalEnd: number;
        penumbralBegin: number;
        penumbralEnd: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates the next lunar eclipse observable from a given location.
   * @param tjd_start The start date to search from. A Julian day in Universal Time.
   * @param ifl The ephemeris flag.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @param backward 1 for backward search, 0 otherwise.
   * @returns The result of the computation or an error.
   */
  export function node_swe_lun_eclipse_when_loc(
    tjd_start: number,
    ifl: number,
    longitude: number,
    latitude: number,
    height: number,
    backward: 0 | 1
  ):
    | {
        rflag: number;
        maximum: number;
        partialBegin: number;
        partialEnd: number;
        totalBegin: number;
        totalEnd: number;
        penumbralBegin: number;
        penumbralEnd: number;
        moonRise: number;
        moonSet: number;
        umbralMagnitude: number;
        penumbralMagnitude: number;
        azimuth: number;
        trueAltitude: number;
        apparentAltitude: number;
        moonDistanceFromOpposition: number;
        sarosNumber: number;
        sarosMember: number;
      }
    | {
        error: string;
      };

  /**
   * Computes data for planetary phenomena at a specified Terrestrial Time.
   * @param tjd The Julian day in Terrestrial Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_pheno(
    tjd: number,
    ipl: number,
    iflag: number
  ):
    | {
        rflag: number;
        phaseAngle: number;
        phase: number;
        elongation: number;
        apparentDiameter: number;
        apparentMagnitude: number;
      }
    | {
        error: string;
      };

  /**
   * Computes data for planetary phenomena at a specified Universal Time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_pheno_ut(
    tjd_ut: number,
    ipl: number,
    iflag: number
  ):
    | {
        rflag: number;
        phaseAngle: number;
        phase: number;
        elongation: number;
        apparentDiameter: number;
        apparentMagnitude: number;
      }
    | {
        error: string;
      };

  /**
   * Converts true to apparent altitude and vice versa.
   * @param inalt The altitude value to convert.
   * @param atpress The atmospheric pressure in mbar (hPa).
   * @param attemp The atmospheric temperature in degrees Celsius.
   * @param calc_flag Either SE_TRUE_TO_APP or SE_APP_TO_TRUE.
   * @returns The result of the computation.
   */
  export function node_swe_refrac(
    inalt: number,
    atpress: number,
    attemp: number,
    calc_flag: typeof SE_TRUE_TO_APP | typeof SE_APP_TO_TRUE
  ): number;

  /**
   * Converts true to apparent altitude and vice versa, supporting negative apparent heights.
   * @param inalt The altitude of object above geometric horizon in degrees,
   *              where geometric horizon = plane perpendicular to gravity.
   * @param geoalt The altitude of observer above sea level in meters.
   * @param atpress The atmospheric pressure in mbar (hPa).
   * @param attemp The atmospheric temperature in degrees Celsius.
   * @param lapse_rate The (dattemp/dgeoalt) value in °K/m.
   * @param calc_flag Either SE_TRUE_TO_APP or SE_APP_TO_TRUE.
   * @returns The result of the computation.
   */
  export function node_swe_refrac_extended(
    inalt: number,
    geoalt: number,
    atpress: number,
    attemp: number,
    lapse_rate: number,
    calc_flag: typeof SE_TRUE_TO_APP | typeof SE_APP_TO_TRUE
  ): {
    refraction: number;
    trueAltitude: number;
    apparentAltitude: number;
    horizonDip: number;
  };

  /**
   * Sets the lapse rate value.
   * @param lapse_rate The new lapse rate value.
   * @returns An empty object.
   */
  export function node_swe_set_lapse_rate(lapse_rate: number): {};

  /**
   * Computes the horizontal coordinates (azimuth and altitude) of a planet or
   * a star from either ecliptical or equatorial coordinates.
   * @param tjd_ut The Julian day in Universal Time.
   * @param calc_flag Either SE_ECL2HOR or SE_EQU2HOR.
   * @param longitude The geographic longitude.
   * @param latitude The geographic latitude.
   * @param height The height above sea.
   * @param atpress The atmospheric pressure in mbar (hPa).
   * @param attemp The atmospheric temperature in degrees Celsius.
   * @param bodyX X coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
   * @param bodyY Y coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
   * @param bodyZ Z coordinate of body in either ecliptical or equatorial coordinates, depending on calc_flag.
   * @returns The result of the computation.
   */
  export function node_swe_azalt(
    tjd_ut: number,
    calc_flag: typeof SE_ECL2HOR | typeof SE_EQU2HOR,
    longitude: number,
    latitude: number,
    height: number,
    atpress: number,
    attemp: number,
    bodyX: number,
    bodyY: number,
    bodyZ: number
  ): {
    azimuth: number;
    trueAltitude: number;
    apparentAltitude: number;
  };

  /**
   * Computes either ecliptical or equatorial coordinates from azimuth and true altitude.
   * @param tjd_ut The Julian day in Universal Time.
   * @param calc_flag Either SE_HOR2ECL or SE_HOR2EQU.
   * @param longitude The geographic longitude of the observer.
   * @param latitude The geographic latitude of the observer.
   * @param height The height of the observer.
   * @param bodyAzimuth The azimuth of the planet.
   * @param bodyTrueAltitude The true altitude of the planet.
   * @returns The result of the computation.
   */
  export function node_swe_azalt_rev(
    tjd_ut: number,
    calc_flag: typeof SE_HOR2ECL | typeof SE_HOR2EQU,
    longitude: number,
    latitude: number,
    height: number,
    bodyAzimuth: number,
    bodyTrueAltitude: number
  ): {
    azimuth: number;
    trueAltitude: number;
  };

  /**
   * Computes the times of rising, setting and meridian transits for planets, asteroids, the moon and the fixed stars.
   * @param tjd_ut Search after this Universal Time.
   * @param ipl The planet number, if planet or moon.
   * @param starname The name of the star. Must be null or "" if ipl is used.
   * @param epheflag The ephemeris flag.
   * @param rsmi Integer specifying that rise, set, or one of the two meridian transits is wanted.
   * @param longitude The geographic longitudeof the observer.
   * @param latitude The geographic latitudeof the observer.
   * @param height The height of the observer.
   * @param atpress The atmospheric pressure in mbar (hPa).
   * @param attemp The atmospheric temperature in degrees Celsius.
   * @returns The result of the computation or an error.
   */
  export function node_swe_rise_trans(
    tjd_ut: number,
    ipl: number,
    starname: string,
    epheflag: number,
    rsmi: number,
    longitude: number,
    latitude: number,
    height: number,
    atpress: number,
    attemp: number
  ):
    | {
        name: string;
        transitTime: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the times of rising, setting and meridian transits for planets, asteroids, the moon and the fixed stars
   * relative to the true horizon.
   * @param tjd_ut Search after this Universal Time.
   * @param ipl The planet number, if planet or moon.
   * @param starname The name of the star. Must be null or "" if ipl is used.
   * @param epheflag The ephemeris flag.
   * @param rsmi Integer specifying that rise, set, or one of the two meridian transits is wanted.
   * @param longitude The geographic longitudeof the observer.
   * @param latitude The geographic latitudeof the observer.
   * @param height The height of the observer.
   * @param atpress The atmospheric pressure in mbar (hPa).
   * @param horhgt Height of local horizon in deg at the point where the body rises or sets.
   * @param attemp The atmospheric temperature in degrees Celsius.
   * @returns The result of the computation or an error.
   */
  export function node_swe_rise_trans_true_hor(
    tjd_ut: number,
    ipl: number,
    starname: string,
    epheflag: number,
    rsmi: number,
    longitude: number,
    latitude: number,
    height: number,
    atpress: number,
    horhgt: number,
    attemp: number
  ):
    | {
        name: string;
        transitTime: number;
      }
    | {
        error: string;
      };
}

export = House;
