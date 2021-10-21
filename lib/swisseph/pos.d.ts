/* eslint-disable camelcase */

declare namespace Pos {
  /**
   * Returns a string with the version number of your Swiss Ephemeris.
   * @returns The version number of your Swiss Ephemeris.
   */
  export function node_swe_version(): string;

  /**
   * Computes the position of a planet, asteroid, lunar node or an apogee for a specified Universal Time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_calc_ut(
    tjd_ut: number,
    ipl: number,
    iflag: number
  ):
    | {
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the position of a planet, asteroid, lunar node or an apogee for a specified Terrestrial Time.
   * @param tjd The Julian day in Terrestrial Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_calc(
    tjd: number,
    ipl: number,
    iflag: number
  ):
    | {
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the position of a fixed star for a specified Terrestrial Time.
   * @param star The search string used to find the fixed star by name.
   *             The search string is treated as having a wildcard at the end.
   * @param tjd The Julian day in Terrestrial Time.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   * @see {@link node_swe_fixstar} for a newer and faster implementation.
   */
  export function node_swe_fixstar(
    star: string,
    tjd: number,
    iflag: number
  ):
    | {
        name: string;
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the position of a fixed star for a specified Universal Time.
   * @param star The search string used to find the fixed star by name.
   *             The search string is treated as having a wildcard at the end.
   * @param tjd_ut The Julian day in Universal Time.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   * @see {@link node_swe_fixstar2_ut} for a newer and faster implementation.
   */
  export function node_swe_fixstar_ut(
    star: string,
    tjd_ut: number,
    iflag: number
  ):
    | {
        name: string;
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Returns the magnitude of a fixed star.
   * @param star The search string used to find the fixed star by name.
   *             The search string is treated as having a wildcard at the end.
   * @returns The magnitude of the fixed star or an error.
   * @see {@link node_swe_fixstar2_mag} for a newer and faster implementation.
   */
  export function node_swe_fixstar_mag(star: string):
    | {
        name: string;
        magnitude: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the position of a fixed star for a specified Terrestrial Time.
   * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
   * @param tjd The Julian day in Terrestrial Time.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_fixstar2(
    star: string,
    tjd: number,
    iflag: number
  ):
    | {
        name: string;
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the position of a fixed star for a specified Universal Time.
   * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
   * @param tjd_ut The Julian day in Universal Time.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_fixstar2_ut(
    star: string,
    tjd_ut: number,
    iflag: number
  ):
    | {
        name: string;
        longitude: number;
        latitude: number;
        distance: number;
        longitudeSpeed: number;
        latitudeSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        rectAscension: number;
        declination: number;
        distance: number;
        rectAscensionSpeed: number;
        declinationSpeed: number;
        distanceSpeed: number;
      }
    | {
        name: string;
        x: number;
        y: number;
        z: number;
        dx: number;
        dy: number;
        dz: number;
      }
    | {
        error: string;
      };

  /**
   * Returns the magnitude of a fixed star.
   * @param star The name of fixed star to be searched. You can specify a '%' sign at the end as a wildcard.
   * @returns The magnitude of the fixed star or an error.
   */
  export function node_swe_fixstar2_mag(star: string):
    | {
        name: string;
        magnitude: number;
      }
    | {
        error: string;
      };

  /**
   * Releases most resources used by the Swiss Ephemeris library.

   * @returns Always undefined.
   */
  export function node_swe_close(): {};

  /**
   * Sets application's own ephemeris path.
   * @param path Path to ephemeris data files.

   * @returns The path as a String object.
   */
  export function node_swe_set_ephe_path(path: string): string;

  /**
   * Sets the name of the JPL ephemeris file.
   * @param fname JPL ephemeris filename.

   * @returns The filename as a String object.
   */
  export function node_swe_set_jpl_file(fname: string): string;

  /**
   * Returns the planetary or asteroid name for a given planet number.
   * @param ipl The planet number.
   * @returns The name of the planet or asteroid.
   */
  export function node_swe_get_planet_name(ipl: number): string;

  /**
   * Sets the geographic location for topocentric planet computations.
   * @param geolon Geographic longitude in degress.
   * @param geolat Geographic latitude in degress.
   * @param geoalt Altitude above sea in meters.

   * @returns Always undefined.
   */
  export function node_swe_set_topo(
    geolon: number,
    geolat: number,
    geoalt: number
  ): {};

  /**
   * Sets the mode for sidereal computations.
   * @param sid_mode The sidereal mode to set.
   * @param t0 Reference epoch.
   * @param ayan_t0 Initial ayanamsha at t0.

   * @returns Always undefined.
   */
  export function node_swe_set_sid_mode(
    sid_mode: number,
    t0: number,
    ayan_t0: number
  ): {};

  /**
   * Returns the ayanamsha for a date in Ephemeris Time.
   * @param tjd_et The Julian day in Ephemeris Time.
   * @returns The ayanamsha for the given date.
   * @see {@link node_swe_get_ayanamsa_ex} for a newer and better implementation.
   */
  export function node_swe_get_ayanamsa(tjd_et: number): number;

  /**
   * Returns the ayanamsha for a date in Universal Time.
   * @param tjd_ut The Julian day in Universal Time.
   * @returns The ayanamsha for the given date.
   * @see {@link node_swe_get_ayanamsa_ex_ut} for a newer and better implementation.
   */
  export function node_swe_get_ayanamsa_ut(tjd_ut: number): number;

  /**
   * Returns the ayanamsha for a date in Ephemeris Time.
   * @param tjd_et The Julian day in Ephemeris Time.
   * @param iflag Ephemeris flag (one of SEFLG_SWIEPH, SEFLG_JPLEPH, SEFLG_MOSEPH).
   * @returns The ayanamsha for the given date or an error.
   */
  export function node_swe_get_ayanamsa_ex(
    tjd_et: number,
    iflag: number
  ):
    | {
        ayanamsa: number;
      }
    | { error: string };

  /**
   * Returns the ayanamsha for a date in Universal Time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param iflag Ephemeris flag (one of SEFLG_SWIEPH, SEFLG_JPLEPH, SEFLG_MOSEPH).
   * @returns The ayanamsha for the given date or an error.
   */
  export function node_swe_get_ayanamsa_ex_ut(
    tjd_ut: number,
    iflag: number
  ):
    | {
        ayanamsa: number;
      }
    | { error: string };

  /**
   * Returns the name of an ayanamsha.
   * @param isidmode The sidereal mode.
   * @returns The name of the ayanamsha.
   */
  export function node_swe_get_ayanamsa_name(isidmode: number): string;

  /**
   * Computes the position of planetary nodes and aspides for a specified Terrestrial Time.
   * @param tjd_et The Julian day in Terrestrial Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @param method The method used for the compuation. (SE_NODBIT_... constants)
   * @returns The result of the computation or an error.
   */
  export function node_swe_nod_aps(
    tjd_et: number,
    ipl: number,
    iflag: number,
    method: number
  ):
    | {
        ascending: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        descending: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        perihelion: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        aphelion: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
      }
    | {
        ascending: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        descending: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        perihelion: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        aphelion: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
      }
    | {
        ascending: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        descending: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        perihelion: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        aphelion: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
      }
    | {
        error: string;
      };

  /**
   * Computes the position of planetary nodes and aspides for a specified Universal Time.
   * @param tjd_ut The Julian day in Universal Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @param method The method used for the compuation. (SE_NODBIT_... constants)
   * @returns The result of the computation or an error.
   */
  export function node_swe_nod_aps_ut(
    tjd_ut: number,
    ipl: number,
    iflag: number,
    method: number
  ):
    | {
        ascending: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        descending: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        perihelion: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
        aphelion: {
          longitude: number;
          latitude: number;
          distance: number;
          longitudeSpeed: number;
          latitudeSpeed: number;
          distanceSpeed: number;
        };
      }
    | {
        ascending: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        descending: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        perihelion: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
        aphelion: {
          rectAscension: number;
          declination: number;
          distance: number;
          rectAscensionSpeed: number;
          declinationSpeed: number;
          distanceSpeed: number;
        };
      }
    | {
        ascending: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        descending: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        perihelion: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
        aphelion: {
          x: number;
          y: number;
          z: number;
          dx: number;
          dy: number;
          dz: number;
        };
      }
    | {
        error: string;
      };

  /**
   * Computes Kepler orbital elements of a planet or asteroid.
   * @param tjd_et The Julian day in Terrestrial Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_get_orbital_elements(
    tjd_et: number,
    ipl: number,
    iflag: number
  ):
    | {
        aphelionDistance: number;
        ascendingNode: number;
        eccentricAnomaly: number;
        eccentricity: number;
        inclination: number;
        meanAnomaly: number;
        meanDailyMotion: number;
        meanLongitude: number;
        periapsis: number;
        periapsisArg: number;
        perihelionDistance: number;
        perihelionPassage: number;
        semimajorAxis: number;
        siderealPeriod: number;
        synodicPeriod: number;
        tropicalPeriod: number;
        trueAnomaly: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the maximum, minimum and current distance of a planet or asteroid.
   * @param tjd_et The Julian day in Terrestrial Time.
   * @param ipl The body number.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_orbit_max_min_true_distance(
    tjd_et: number,
    ipl: number,
    iflag: number
  ):
    | {
        maxDistance: number;
        minDistance: number;
        trueDistance: number;
      }
    | {
        error: string;
      };
}

export = Pos;
