
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace BeaverKart64
{
    class BeaverKart64Requests
    {
    public:
        AZ_RTTI(BeaverKart64Requests, "{c3034b7d-4cf2-49a1-ba4c-8fab0769579f}");
        virtual ~BeaverKart64Requests() = default;
        // Put your public methods here
    };
    
    class BeaverKart64BusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BeaverKart64RequestBus = AZ::EBus<BeaverKart64Requests, BeaverKart64BusTraits>;
    using BeaverKart64Interface = AZ::Interface<BeaverKart64Requests>;

} // namespace BeaverKart64
