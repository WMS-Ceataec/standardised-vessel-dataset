/**
 * Represents the "Cargo Information" section of the SVD.
 */
export type CargoInformation = {
  /**
   * A description of the referenced packaged cargo.
   */
  CargoDescription: string;

  /**
   * The combined weight or mass of the referenced packaged cargo and its packaging from the shipping data, in kilograms (kg).
   */
  GrossWeight: number;

  /**
   * A measure of the gross volume, normally calculated by multiplying the maximum length, width, and height of the cargo item.
   */
  GrossVolume: number;

  /**
   * A reference number issued on the bill of lading.
   */
  BillOfLadingReference: string;

  /**
   * The date when the bill of lading is issued.
   */
  BillOfLadingIssuedDate: Date;

  /**
   * The total number of containers onboard (full and empty), measured in TEU (Twenty-Foot Equivalent Unit).
   */
  TotalContainersTEU: number;

  /**
   * The total number of full containers onboard, measured in TEU (Twenty-Foot Equivalent Unit).
   */
  TotalFullContainersTEU: number;

  /**
   * The total number of full reefer containers onboard in use, measured in TEU (Twenty-Foot Equivalent Unit).
   */
  TotalFullReeferContainersTEU: number;

  /**
   * The total number of reefer power sockets in use during the voyage.
   */
  ReeferSocketsInUse: number;

  /**
   * The total count of 20-foot containers onboard that are filled with chilled or refrigerated goods.
   */
  Chilled20FtReeferContainers: number;

  /**
   * The total count of 40-foot containers onboard that are filled with chilled or refrigerated goods.
   */
  Chilled40FtReeferContainers: number;

  /**
   * The total count of 20-foot containers onboard that are filled with frozen goods.
   */
  Frozen20FtReeferContainers: number;

  /**
   * The total count of 40-foot containers onboard that are filled with frozen goods.
   */
  Frozen40FtReeferContainers: number;

  /**
   * The total number of vehicles onboard, measured in CEU (Car Equivalent Unit).
   */
  TotalVehiclesCEU: number;
};