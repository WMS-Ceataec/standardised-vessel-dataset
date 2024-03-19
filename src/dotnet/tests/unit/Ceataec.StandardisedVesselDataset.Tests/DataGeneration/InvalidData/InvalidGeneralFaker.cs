﻿using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.InvalidData;

internal sealed class InvalidGeneralFaker : Faker<General>
{
    internal InvalidGeneralFaker()
    {
        RuleFor(e => e.VesselName, _ => string.Empty);
        RuleFor(e => e.Imo, _ => string.Empty);
        RuleFor(e => e.Time, f => f.Date.Future());
    }
}