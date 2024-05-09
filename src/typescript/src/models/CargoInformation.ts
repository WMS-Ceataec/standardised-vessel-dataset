/**
 * Represents the "Cargo Information" section of the SVD.
 */
export type CargoInformation = {
    /**
     * Description of the referenced packaged cargo.
     */
    CargoDescription: string;

    /**
     * Combined weight or mass of the referenced packaged cargo and its packaging from the shipping data, in kilograms (kg).
     */
    GrossWeight: number;

    /**
     * Measure of the gross volume, normally calculated by multiplying the maximum length, width and height of the cargo item.
     */
    GrossVolume: number;

    /**
     * Total number of containers on board, measured in TEU (Twenty-Foot Equivalent Unit).
     */
    TotalContainersTEU: number;

    /**
     * Total number of full containers on board, measured in TEU (Twenty-Foot Equivalent Unit).
     */
    TotalFullContainersTEU: number;

    /**
     * Total number of full reefer containers on board in use, measured in TEU (Twenty-Foot Equivalent Unit).
     */
    TotalFullReeferContainersTEU: number;

    /**
     * Total number of vehicles on board, measured in CEU (Car Equivalent Unit).
     */
    TotalVehiclesCEU: number;
};
