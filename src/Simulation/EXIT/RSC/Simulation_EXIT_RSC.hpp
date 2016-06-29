#ifndef SIMULATION_EXIT_RSC_HPP_
#define SIMULATION_EXIT_RSC_HPP_

#include <chrono>
#include <vector>
#include "../../../Tools/MIPP/mipp.h"

#include "../Simulation_EXIT.hpp"

template <typename B, typename R, typename Q, typename QD>
class Simulation_EXIT_RSC : public Simulation_EXIT<B,R,Q>
{
protected:
	// the trellis representation
	mipp::vector<mipp::vector<int>> trellis;
	
public:
	Simulation_EXIT_RSC(const t_simulation_param& simu_params,
	                    const t_code_param&       code_params,
	                    const t_encoder_param&    enco_params,
	                    const t_channel_param&    chan_params,
	                    const t_decoder_param&    deco_params);
	virtual ~Simulation_EXIT_RSC();

protected:
	void extract_sys_par(const mipp::vector<Q> &Lch_N2, 
	                     const mipp::vector<Q> &La_K2, 
	                           mipp::vector<Q> &sys, 
	                           mipp::vector<Q> &par);

	void        launch_precompute();
	void        snr_precompute   ();
	Encoder<B>* build_encoder    ();
	SISO<Q>*    build_siso       ();
};

#endif /* SIMULATION_EXIT_RSC_HPP_ */