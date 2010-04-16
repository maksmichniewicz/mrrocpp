// -------------------------------------------------------------------------
//                            ecp.h dla QNX6
// Definicje struktur danych i metod dla procesow ECP
// robot - speaker
//
// -------------------------------------------------------------------------

#if !defined(_ECP_R_SPEAKER_H)
#define _ECP_R_SPEAKER_H

#include "ecp/common/ecp_robot.h"
#include "lib/robot_consts/speaker_const.h"

namespace mrrocpp {
namespace ecp {
namespace speaker {

// ---------------------------------------------------------------
class robot: public common::ecp_robot
{
	// Klasa dla robota speaker

	public:
	robot (lib::configurator &_config, lib::sr_ecp &_sr_ecp);
	robot (common::task::task& _ecp_object);



}; // end: class ecp_speaker_robot
// ---------------------------------------------------------------

} // namespace speaker
} // namespace ecp
} // namespace mrrocpp

#endif
