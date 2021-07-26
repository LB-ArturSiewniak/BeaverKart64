
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BeaverKart64SystemComponent.h"

namespace BeaverKart64
{
    void BeaverKart64SystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BeaverKart64SystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BeaverKart64SystemComponent>("BeaverKart64", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BeaverKart64SystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BeaverKart64Service"));
    }

    void BeaverKart64SystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BeaverKart64Service"));
    }

    void BeaverKart64SystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BeaverKart64SystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    BeaverKart64SystemComponent::BeaverKart64SystemComponent()
    {
        if (BeaverKart64Interface::Get() == nullptr)
        {
            BeaverKart64Interface::Register(this);
        }
    }

    BeaverKart64SystemComponent::~BeaverKart64SystemComponent()
    {
        if (BeaverKart64Interface::Get() == this)
        {
            BeaverKart64Interface::Unregister(this);
        }
    }

    void BeaverKart64SystemComponent::Init()
    {
    }

    void BeaverKart64SystemComponent::Activate()
    {
        BeaverKart64RequestBus::Handler::BusConnect();
    }

    void BeaverKart64SystemComponent::Deactivate()
    {
        BeaverKart64RequestBus::Handler::BusDisconnect();
    }
}
