#ifndef __swisseph_house_h__
#define __swisseph_house_h__

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
Napi::Object node_swe_houses(const Napi::CallbackInfo& info);

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
Napi::Object node_swe_houses_ex(const Napi::CallbackInfo& info);

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
Napi::Object node_swe_houses_ex2(const Napi::CallbackInfo& info);

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
Napi::Object node_swe_houses_armc(const Napi::CallbackInfo& info);

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
Napi::Object node_swe_houses_armc_ex2(const Napi::CallbackInfo& info);

/**
 * double swe_houses_pos(double armc, double geolat, double eps, int hsys, double *xpin, char *serr)
 * =>
 * node_swe_houses_pos: (armc: number, geolat: number, eps: number, hsys: string, lon: number, lat: number) => {
 *   housePosition:	number
 * } | {
 *   error:	string
 * }
 */
Napi::Object node_swe_houses_pos(const Napi::CallbackInfo& info);

#endif