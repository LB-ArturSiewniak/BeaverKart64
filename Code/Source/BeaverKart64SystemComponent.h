
#pragma once

#include <AzCore/Component/Component.h>

#include <BeaverKart64/BeaverKart64Bus.h>

namespace BeaverKart64
{
    class BeaverKart64SystemComponent
        : public AZ::Component
        , protected BeaverKart64RequestBus::Handler
    {
    public:
        AZ_COMPONENT(BeaverKart64SystemComponent, "{14805881-f277-4809-ac25-e411a879da49}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BeaverKart64SystemComponent();
        ~BeaverKart64SystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BeaverKart64RequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
