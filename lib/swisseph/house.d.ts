/* eslint-disable camelcase */

declare namespace House {
  /**
   * Calculates houses for a given date and geographic position.
   * @param tjd_ut The Julian day in Universal Time.
   * @param geolat The geographic latitude.
   * @param geolon The geographic longitude.
   * @param hsys A letter defining the house method used for the calculation.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses(
    tjd_ut: number,
    geolat: number,
    geolon: number,
    hsys: string
  ):
    | {
        house: number[];
        ascendant: number;
        mc: number;
        armc: number;
        vertex: number;
        equatorialAscendant: number;
        kochCoAscendant: number;
        munkaseyCoAscendant: number;
        munkaseyPolarAscendant: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates houses and tropical or sidereal positions for a given date and geographic position.
   * @param tjd_ut The Julian day in Universal Time.
   * @param iflag 0 or SEFLG_SIDEREAL or SEFLG_RADIANS.
   * @param geolat The geographic latitude.
   * @param geolon The geographic longitude.
   * @param hsys A letter defining the house method used for the calculation.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses_ex(
    tjd_ut: number,
    iflag: number,
    geolat: number,
    geolon: number,
    hsys: string
  ):
    | {
        house: number[];
        ascendant: number;
        mc: number;
        armc: number;
        vertex: number;
        equatorialAscendant: number;
        kochCoAscendant: number;
        munkaseyCoAscendant: number;
        munkaseyPolarAscendant: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates houses and tropical or sidereal positions for a given date and geographic position.
   * This function also returns the speeds (daily motions) of the ascendant, midheaven and house cusps.
   * @param tjd_ut The Julian day in Universal Time.
   * @param iflag 0 or SEFLG_SIDEREAL or SEFLG_RADIANS or SEFLG_NONUT.
   * @param geolat The geographic latitude.
   * @param geolon The geographic longitude.
   * @param hsys A letter defining the house method used for the calculation.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses_ex2(
    tjd_ut: number,
    iflag: number,
    geolat: number,
    geolon: number,
    hsys: string
  ):
    | {
        house: number[];
        ascendant: number;
        mc: number;
        armc: number;
        vertex: number;
        equatorialAscendant: number;
        kochCoAscendant: number;
        munkaseyCoAscendant: number;
        munkaseyPolarAscendant: number;
        houseSpeed: number[];
        ascendantSpeed: number;
        mcSpeed: number;
        armcSpeed: number;
        vertexSpeed: number;
        equatorialAscendantSpeed: number;
        kochCoAscendantSpeed: number;
        munkaseyCoAscendantSpeed: number;
        munkaseyPolarAscendantSpeed: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates houses from a given ARMC (e.g. from a composite horoscope) when the date is not known.
   * @param armc The Ascensio Recta Medii Coeli value.
   * @param geolat The geographic latitude.
   * @param eps The ecliptic obliquity, in degrees.
   * @param hsys A letter defining the house method used for the calculation.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses_armc(
    armc: number,
    geolat: number,
    eps: number,
    hsys: string
  ):
    | {
        house: number[];
        ascendant: number;
        mc: number;
        armc: number;
        vertex: number;
        equatorialAscendant: number;
        kochCoAscendant: number;
        munkaseyCoAscendant: number;
        munkaseyPolarAscendant: number;
      }
    | {
        error: string;
      };

  /**
   * Calculates houses from a given ARMC (e.g. from a composite horoscope) when the date is not known.
   * This function also returns the speeds (daily motions) of the ascendant, midheaven and house cusps.
   * @param armc The Ascensio Recta Medii Coeli value.
   * @param geolat The geographic latitude.
   * @param eps The ecliptic obliquity, in degrees.
   * @param hsys A letter defining the house method used for the calculation.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses_armc_ex2(
    armc: number,
    geolat: number,
    eps: number,
    hsys: string
  ):
    | {
        house: number[];
        ascendant: number;
        mc: number;
        armc: number;
        vertex: number;
        equatorialAscendant: number;
        kochCoAscendant: number;
        munkaseyCoAscendant: number;
        munkaseyPolarAscendant: number;
        houseSpeed: number[];
        ascendantSpeed: number;
        mcSpeed: number;
        armcSpeed: number;
        vertexSpeed: number;
        equatorialAscendantSpeed: number;
        kochCoAscendantSpeed: number;
        munkaseyCoAscendantSpeed: number;
        munkaseyPolarAscendantSpeed: number;
      }
    | {
        error: string;
        message: string;
      };

  /**
   * Computes the house position of a given body for a given ARMC.
   * @param armc The Ascensio Recta Medii Coeli value.
   * @param geolat The geographic latitude.
   * @param eps The ecliptic obliquity, in degrees.
   * @param hsys A letter defining the house method used for the calculation.
   * @param lon The ecliptic longitude of the planet, in degrees.
   * @param lat The ecliptic latitude of the planet, in degrees.
   * @returns The result of the computation or an error.
   */
  export function node_swe_houses_pos(
    armc: number,
    geolat: number,
    eps: number,
    hsys: string,
    lon: number,
    lat: number
  ):
    | {
        housePosition: number;
      }
    | {
        error: string;
      };
}

export = House;
