/* eslint-disable camelcase */

declare namespace Hel {
  /**
   * Computes the Julian day of the next heliacal phenomenon after a given start date.
   * It works between geographic latitudes 60s – 60n.
   * @param tjdstart_ut The Julian day number of start date for the search of the heliacal event.
   * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
   * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
   *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
   * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
   *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
   *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
   * @param ObjectName The name string of fixed star or planet.
   * @param TypeEvent The event type.
   * @param iflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_heliacal_ut(
    tjdstart_ut: number,
    geopos: [number, number, number],
    datm: [number, number, number, number],
    dobs: [number, number, number, number, number, number],
    ObjectName: string,
    TypeEvent: number,
    iflag: number
  ):
    | {
        startVisible: number;
        bestVisible: number;
        endVisible: number;
      }
    | {
        error: string;
      };

  /**
   * Computes data that is relevant for the calculation of heliacal risings and settings.
   * @param tjd_ut The Julian day number of the event.
   * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
   * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
   *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
   * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
   *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
   *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
   * @param ObjectName The name string of fixed star or planet.
   * @param TypeEvent The event type.
   * @param helflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_heliacal_pheno_ut(
    tjd_ut: number,
    geopos: [number, number, number],
    datm: [number, number, number, number],
    dobs: [number, number, number, number, number, number],
    ObjectName: string,
    TypeEvent: number,
    helflag: number
  ):
    | {
        tcAltitude: number;
        tcApparentAltitude: number;
        gcAltitude: number;
        azimuth: number;
        tcSunAltitude: number;
        sunAzimuth: number;
        tcActualVisibleArc: number;
        gcActualVisibleArc: number;
        objectToSunAzimuth: number;
        objectToSunLongitude: number;
        extinction: number;
        tcMinVisibleArc: number;
        firstVisible: number;
        bestVisible: number;
        endVisible: number;
        yallopBestVisible: number;
        moonCresentWidth: number;
        yallopValue: number;
        yallopCriterion: number;
        parallax: number;
        magnitude: number;
        rise: number;
        riseSet: number;
        riseObjectToSun: number;
        visibleDuration: number;
        moonCresetLength: number;
        elong: number;
        illumination: number;
        kOZ: number;
        ka: number;
        ksumm: number;
      }
    | {
        error: string;
      };

  /**
   * Computes the limiting visual magnitude in dark skies for heliacal phenomenon.
   * @param tjdut The Julian day number of the event.
   * @param geopos The geographic position: [0] = longitude, [1] = latitude, [2] = altitude (eye height) in meters
   * @param datm The atmospheric conditions: [0] = pressure in mbar (hPa), [1] = temperature in degrees Celsius,
   *             [2] = relative humidity in %, [3] = meteorological range (km) or total atmospheric coefficient (ktot)
   * @param dobs The observer description: [0] = age of observer in years, [1] = Snellen ratio of observers eyes,
   *             [2] = 0 = monocular, 1 = binocular, [3] = telescope magnification,
   *             [4] = optical aperture (telescope diameter) in mm, [5] = optical transmission
   * @param ObjectName The name string of fixed star or planet.
   * @param helflag A 32 bit integer containing bit flags that indicate what kind of computation is wanted.
   * @returns The result of the computation or an error.
   */
  export function node_swe_vis_limit_mag(
    tjdut: number,
    geopos: [number, number, number],
    datm: [number, number, number, number],
    dobs: [number, number, number, number, number, number],
    ObjectName: string,
    helflag: number
  ):
    | {
        vissualMagnitudeLimit: number;
        AltO: number;
        AziO: number;
        AltS: number;
        AziS: number;
        AltM: number;
        AziM: number;
      }
    | {
        error: string;
      };
}

export = Hel;
