
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BeaverKart64SystemComponent.h"

namespace BeaverKart64
{
    class BeaverKart64Module
        : public AZ::Module
    {
    public:
        AZ_RTTI(BeaverKart64Module, "{f809e2f3-2baf-4a33-ac2a-132eb5e8974d}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BeaverKart64Module, AZ::SystemAllocator, 0);

        BeaverKart64Module()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BeaverKart64SystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BeaverKart64SystemComponent>(),
            };
        }
    };
}// namespace BeaverKart64

AZ_DECLARE_MODULE_CLASS(Gem_BeaverKart64, BeaverKart64::BeaverKart64Module)
