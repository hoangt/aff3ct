#ifndef ENCODER_HPP_
#define ENCODER_HPP_

#include <string>
#include <vector>
#include "Tools/MIPP/mipp.h"

template <typename B>
class Encoder_interface // please use Encoder<B> for inheritance (instead of Encoder_interface<B>)
{
protected:
	const int K; // number of information bits in the frame size
	const int N; // frame size
	      int n_frames;

	const std::string name; // module name

public:
	Encoder_interface(const int K, const int N, const int n_frames = 1, const std::string name = "Encoder_interface") 
	: K(K), N(N), n_frames(n_frames), name(name) {};
	virtual ~Encoder_interface() {};

	virtual void encode(const mipp::vector<B>& U_K, mipp::vector<B>& X_N) = 0;

	virtual int tail_length() const { return 0; }

	virtual void set_n_frames(const int n_frames) 
	{ 
		assert(n_frames > 0);
		this->n_frames = n_frames; 
	}
};

#include "SC_Encoder.hpp"

#endif /* ENCODER_HPP_ */