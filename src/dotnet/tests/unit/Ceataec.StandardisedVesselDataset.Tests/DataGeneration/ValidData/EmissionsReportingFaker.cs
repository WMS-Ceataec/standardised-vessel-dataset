﻿using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class EmissionsReportingFaker : Faker<EmissionsReporting>
    {
        public EmissionsReportingFaker()
        {
            RuleFor(er => er.Co2EmissionFactorEthanol, f => f.Random.Number());
        }
    }
}