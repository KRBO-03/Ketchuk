/* Automation Studio generated header file */
/* Do not edit ! */
/* MotrContr  */

#ifndef _MOTRCONTR_
#define _MOTRCONTR_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef enum axis_states
{	B,
	B_dir,
	A,
	A_dir,
	unknown
} axis_states;

typedef struct FB_Integrator
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float dt;
	float state;
} FB_Integrator_typ;

typedef struct FB_Motor
{
	/* VAR_INPUT (analog) */
	float u;
	/* VAR_OUTPUT (analog) */
	float w;
	float phi;
	/* VAR (analog) */
	struct FB_Integrator integrator;
	float Tm;
	float ke;
	float dt;
} FB_Motor_typ;

typedef struct FB_Regulator
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float k_i;
	float sum;
	float k_p;
	float dt;
	float max_abs_value;
	struct FB_Integrator integrator;
	float last_sum;
} FB_Regulator_typ;

typedef struct FB_Axis
{
	/* VAR_INPUT (analog) */
	float u;
	signed short state;
	/* VAR_OUTPUT (analog) */
	signed short pwm_value;
	signed short counter;
	float speed;
	/* VAR (analog) */
	signed short last_counter;
	/* VAR_INPUT (digital) */
	plcbit reset_error;
	plcbit endswitch_a_reached;
	plcbit endswitch_b_reached;
	plcbit button_a;
	plcbit button_b;
	plcbit direction;
	/* VAR_OUTPUT (digital) */
	plcbit reset_counter;
} FB_Axis_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FB_Integrator(struct FB_Integrator* inst);
_BUR_PUBLIC void FB_Motor(struct FB_Motor* inst);
_BUR_PUBLIC void FB_Regulator(struct FB_Regulator* inst);
_BUR_PUBLIC void FB_Axis(struct FB_Axis* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MOTRCONTR_ */

