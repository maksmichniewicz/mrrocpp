/*
 * $Id: ecp_t_ib_eih_tester.h 3480 2010-01-08 18:48:29Z mboryn $
 *
 *  Created on: Dec 11, 2009
 *      Author: mboryn
 */

#ifndef ECP_T_IB_EIH_TESTER_H_
#define ECP_T_IB_EIH_TESTER_H_

#include "ecp/common/task/ecp_task.h"
#include "ecp/irp6_on_track/ecp_r_irp6ot.h"
#include "ecp_mp/sensor/ecp_mp_s_fradia_sensor.h"
#include "ecp/common/generator/ecp_g_smooth.h"
#include "../ib_eih/ecp_g_ib_eih.h"

namespace mrrocpp {

namespace ecp {

namespace irp6ot {

namespace task {

/** @addtogroup servovision Visual servomechanism implementation
 *  @ingroup application
 *  IB EIH Servovision tester
 *  @{
 */

/**
 *
 */
class ecp_t_ib_eih_tester: public mrrocpp::ecp::common::task::task
{
public:
	ecp_t_ib_eih_tester(mrrocpp::lib::configurator& _configurator);
	virtual ~ecp_t_ib_eih_tester();
	void main_task_algorithm(void);
protected:
	lib::sensor *vsp_fradia;
	mrrocpp::ecp::common::generator::smooth* smooth_gen;
	mrrocpp::ecp::irp6ot::generator::ecp_g_ib_eih *g_ib_eih;

	/** Moves (using smooth generator) to initial position. */
	void moveToInitialPosition();

	/*static const double initialPositionJoints[MAX_SERVOS_NR] = {
	 0, -0.013, -1.442, -0.275, 0.01, 4.686, -0.070, 0.090
	 };*/
	static const double initialPositionJoints[MAX_SERVOS_NR];
};

/** @} */// ecp_t_ib_eih_tester

} // namespace task

} // namespace irp6ot

} // namespace ecp

} // namespace mrrocpp

#endif /* ECP_T_IB_EIH_TESTER_H_ */