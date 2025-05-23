/**
* Represent the "Fresh Water" section of SVD
*/
export type FreshWater = {
  /**
   * Fresh water bunkered on board, measured in metric tons.
   */
  FreshWaterBunkered: number;

  /**
   * Fresh water produced on board by running the fresh water generator, measured in metric tons.
   */
  FreshWaterProduced: number;

  /**
   * Fresh water (drinking water) consumed on board, measured in metric tons.
   */
  FreshWaterConsumed: number;

  /**
   * Technical water (< 15 ppm) produced on board, measured in metric tons.
   */
  TechnicalWaterProduced: number;

  /**
   * Technical water (< 15 ppm) consumed on board, measured in metric tons.
   */
  TechnicalWaterConsumed: number;

  /**
   * Wash water (for exhaust gas cleaning systems) consumed on board, measured in metric tons.
   */
  WashWaterConsumed: number;

  /**
   * Fresh drinking water remaining on board, measured in metric tons.
   */
  FreshWaterRemaining: number;
};