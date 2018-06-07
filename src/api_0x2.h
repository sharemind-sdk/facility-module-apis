/*
 * Copyright (C) Cybernetica
 *
 * Research/Commercial License Usage
 * Licensees holding a valid Research License or Commercial License
 * for the Software may use this file according to the written
 * agreement between you and Cybernetica.
 *
 * GNU General Public License Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPLv3 included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl-3.0.html.
 *
 * For further information, please contact us at sharemind@cyber.ee.
 */

#ifndef SHAREMIND_FACILITY_MODULE_APIS_API_0x2_H
#define SHAREMIND_FACILITY_MODULE_APIS_API_0x2_H

#include <memory>
#include <string>
#include "api.h"


namespace sharemind {
namespace FacilityModuleApis {
namespace v2 {

using FacilitySharedPtr = std::shared_ptr<void>; // Guaranteed!

template <typename Context>
struct FacilityFactory {

    virtual FacilitySharedPtr createFacility(Context const & context) = 0;

}; /* struct FacilityFactory { */

struct FacilityModuleFacilityFactoryContext {

    virtual FacilitySharedPtr findFacilityModuleFacility(
            char const * facilityName) const noexcept = 0;
    virtual FacilitySharedPtr findFacilityModuleFacility(
            std::string const & facilityName) const noexcept = 0;

}; /* struct FacilityModuleFacilityFactoryContext { */

using FacilityModuleFacilityFactory =
        FacilityFactory<FacilityModuleFacilityFactoryContext>;

struct ModuleFacilityFactoryContext {

    virtual FacilitySharedPtr findModuleFacility(char const * facilityName)
            const noexcept = 0;
    virtual FacilitySharedPtr findModuleFacility(
            std::string const & facilityName) const noexcept = 0;

}; /* struct ModuleFacilityFactoryContext { */

using ModuleFacilityFactory = FacilityFactory<ModuleFacilityFactoryContext>;

struct PdFacilityFactoryContext: ModuleFacilityFactoryContext {

    virtual FacilitySharedPtr findPdFacility(char const * facilityName)
            const noexcept = 0;
    virtual FacilitySharedPtr findPdFacility(std::string const & facilityName)
            const noexcept = 0;

}; /* struct PdFacilityFactoryContext */

using PdFacilityFactory = FacilityFactory<PdFacilityFactoryContext>;

struct PdpiFacilityFactoryContext: PdFacilityFactoryContext {

    virtual FacilitySharedPtr findPdpiFacility(char const * facilityName)
            const noexcept = 0;
    virtual FacilitySharedPtr findPdpiFacility(std::string const & facilityName)
            const noexcept = 0;

}; /* struct PdpiFacilityFactoryContext */

using PdpiFacilityFactory = FacilityFactory<PdpiFacilityFactoryContext>;

struct ProcessFacilityFactoryContext {

    virtual FacilitySharedPtr findProcessFacility(char const * facilityName)
            const noexcept = 0;
    virtual FacilitySharedPtr findProcessFacility(
            std::string const & facilityName) const noexcept = 0;

}; /* struct ProcessFacilityFactoryContext { */

using ProcessFacilityFactory = FacilityFactory<ProcessFacilityFactoryContext>;

struct ModuleInitContext {

    virtual std::string const & moduleConfigurationString() const noexcept = 0;

    virtual FacilitySharedPtr findFacilityModuleFacility(
            char const * facilityName) const noexcept = 0;
    virtual FacilitySharedPtr findFacilityModuleFacility(
            std::string const & facilityName) const noexcept = 0;

    virtual void registerFacilityModuleFacility(std::string facilityName,
                                                FacilitySharedPtr facility) = 0;
    virtual void registerFacilityModuleFacilityFactory(
            std::string facilityName,
            std::shared_ptr<FacilityModuleFacilityFactory> facilityFactory) = 0;

    virtual void registerModuleFacility(std::string facilityName,
                                        FacilitySharedPtr facility) = 0;
    virtual void registerModuleFacilityFactory(
            std::string facilityName,
            std::shared_ptr<ModuleFacilityFactory> facilityFactory) = 0;

    virtual void registerPdFacility(std::string facilityName,
                                    FacilitySharedPtr facility) = 0;
    virtual void registerPdFacilityFactory(
                std::string facilityName,
                std::shared_ptr<PdFacilityFactory> facilityFactory) = 0;

    virtual void registerPdpiFacility(std::string facilityName,
                                      FacilitySharedPtr facility) = 0;
    virtual void registerPdpiFacilityFactory(
            std::string facilityName,
            std::shared_ptr<PdpiFacilityFactory> facilityFactory) = 0;

    virtual void registerProcessFacility(std::string facilityName,
                                         FacilitySharedPtr facility) = 0;
    virtual void registerProcessFacilityFactory(
            std::string facilityName,
            std::shared_ptr<ProcessFacilityFactory> facilityFactory) = 0;

}; /* struct ModuleInitContext { */

struct FacilityModuleInfo {

    void (* const initializeModule)(ModuleInitContext & context);

}; /* struct ModuleInfo { */

} /* namespace v2 { */
} /* namespace FacilityModuleApis { */
} /* namespace sharemind { */

#endif /* SHAREMIND_FACILITY_MODULE_APIS_API_0x2_H */
