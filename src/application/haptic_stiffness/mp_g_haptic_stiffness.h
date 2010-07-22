// -------------------------------------------------------------------------
//
// Definicje struktur danych i metod dla procesow MP - generatory silowe
//
// -------------------------------------------------------------------------

#if !defined(__MP_GEN_HAPTIC_STIFFNESS_H)
#define __MP_GEN_HAPTIC_STIFFNESS_H

#include "lib/mrmath/mrmath.h"

#include "base/mp/mp_generator.h"

namespace mrrocpp {
namespace mp {
namespace generator {

#define MINIMAL_FORCE 1.0
#define FORCE_INCREMENT 5.0
#define POSITION_INCREMENT 0.01

enum HAPTIC_STIFFNESS_STATES {
	HS_LOW_FORCE = 0,
	HS_STIFNESS_ESTIMATION
};


/** @addtogroup haptic_stiffness
 *
 *  @{
 */

// --------------------------------------------------------------------------
// Generator trajektorii dla zadan z wodzeniem za nos w tff ze zmiana orientacji

class haptic_stiffness : public generator
{
protected:
	robot::robot *irp6ot, *irp6p;

	HAPTIC_STIFFNESS_STATES state;
	double stiffness;
	double initial_force;
	double initial_position;

	// do konfiguracji pracy generatora
	unsigned short irp6ot_con, irp6p_con;
	const lib::Homog_matrix global_base;

	lib::trajectory_description td;

public:
	int step_no;

	// konstruktor
	haptic_stiffness(task::task& _mp_task, int step = 0);

	void configure(unsigned short l_irp6ot_con, unsigned short l_irp6p_con);

	virtual bool first_step();
	virtual bool next_step();

}; // end : class haptic_stiffness

/** @} */// end of edge_following

} // namespace generator
} // namespace mp
} // namespace mrrocpp

#endif
