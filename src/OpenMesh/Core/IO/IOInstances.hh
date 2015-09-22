/*===========================================================================*\
 *                                                                           *
 *                               OpenMesh                                    *
 *      Copyright (C) 2001-2010 by Computer Graphics Group, RWTH Aachen      *
 *                           www.openmesh.org                                *
 *                                                                           *
 *---------------------------------------------------------------------------* 
 *  This file is part of OpenMesh.                                           *
 *                                                                           *
 *  OpenMesh is free software: you can redistribute it and/or modify         * 
 *  it under the terms of the GNU Lesser General Public License as           *
 *  published by the Free Software Foundation, either version 3 of           *
 *  the License, or (at your option) any later version with the              *
 *  following exceptions:                                                    *
 *                                                                           *
 *  If other files instantiate templates or use macros                       *
 *  or inline functions from this file, or you compile this file and         *
 *  link it with other files to produce an executable, this file does        *
 *  not by itself cause the resulting executable to be covered by the        *
 *  GNU Lesser General Public License. This exception does not however       *
 *  invalidate any other reasons why the executable file might be            *
 *  covered by the GNU Lesser General Public License.                        *
 *                                                                           *
 *  OpenMesh is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU Lesser General Public License for more details.                      *
 *                                                                           *
 *  You should have received a copy of the GNU LesserGeneral Public          *
 *  License along with OpenMesh.  If not,                                    *
 *  see <http://www.gnu.org/licenses/>.                                      *
 *                                                                           *
\*===========================================================================*/ 

/*===========================================================================*\
 *                                                                           *             
 *   $Revision: 325 $                                                         *
 *   $Date: 2010-06-17 12:45:58 +0200 (Do, 17 Jun 2010) $                   *
 *                                                                           *
\*===========================================================================*/


//=============================================================================
//
//  Helper file for static builds
//
//  In opposite to dynamic builds where the instance of every reader module
//  is generated within the OpenMesh library, static builds only instanciate
//  objects that are at least referenced once. As all reader modules are
//  never used directly, they will not be part of a static build, hence
//  this file.
//
//=============================================================================


#ifndef __IOINSTANCES_HH__
#define __IOINSTANCES_HH__

#if defined(OM_STATIC_BUILD) || defined(ARCH_DARWIN)

//=============================================================================

#include <OpenMesh/Core/System/config.h>

#include <OpenMesh/Core/IO/reader/BaseReader.hh>
#include <OpenMesh/Core/IO/reader/OBJReader.hh>
#include <OpenMesh/Core/IO/reader/OFFReader.hh>
#include <OpenMesh/Core/IO/reader/PLYReader.hh>
#include <OpenMesh/Core/IO/reader/STLReader.hh>
#include <OpenMesh/Core/IO/reader/OMReader.hh>

#include <OpenMesh/Core/IO/writer/BaseWriter.hh>
#include <OpenMesh/Core/IO/writer/OBJWriter.hh>
#include <OpenMesh/Core/IO/writer/OFFWriter.hh>
#include <OpenMesh/Core/IO/writer/STLWriter.hh>
#include <OpenMesh/Core/IO/writer/OMWriter.hh>
#include <OpenMesh/Core/IO/writer/PLYWriter.hh>

//=== NAMESPACES ==============================================================

namespace OpenMesh {
namespace IO {

//=============================================================================

#if defined(__GNUC__)
// GCC and clang provide an attribute to avoid unused variable warnings
#  define OM_UNUSED __attribute__ ((__unused__))
#else
// Default to empty define which may leave warnings, but shouldn't cause errors
#  define OM_UNUSED
#endif

// Instanciate every Reader module
OM_UNUSED static BaseReader* OFFReaderInstance = &OFFReader();
OM_UNUSED static BaseReader* OBJReaderInstance = &OBJReader();
OM_UNUSED static BaseReader* PLYReaderInstance = &PLYReader();
OM_UNUSED static BaseReader* STLReaderInstance = &STLReader();
OM_UNUSED static BaseReader* OMReaderInstance  = &OMReader();

// Instanciate every writer module
OM_UNUSED static BaseWriter* OBJWriterInstance = &OBJWriter();
OM_UNUSED static BaseWriter* OFFWriterInstance = &OFFWriter();
OM_UNUSED static BaseWriter* STLWriterInstance = &STLWriter();
OM_UNUSED static BaseWriter* OMWriterInstance  = &OMWriter();
OM_UNUSED static BaseWriter* PLYWriterInstance = &PLYWriter();

#undef OM_UNUSED

//=============================================================================
} // namespace IO
} // namespace OpenMesh
//=============================================================================
#endif // static ?
#endif //__IOINSTANCES_HH__
//=============================================================================
