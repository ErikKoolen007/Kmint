#include "cow.h"
#include "kmint/random.hpp"
using namespace kmint;

static const char *cow_image = "resources/cow.png";
cow::cow(map::map_graph const &g, map::map_node const &initial_node)
	: kmint::play::map_bound_actor{ g, initial_node }, drawable_{ *this,
														kmint::graphics::image{
															cow_image, 0.1} } {}

void cow::act(delta_time dt) {
	t_passed_ += dt;
	if (to_seconds(t_passed_) >= 1) {
		if (!path_.empty()) {
			for(size_t i = 0; i < this->node().num_edges(); i++)
			{
				auto test = this->node()[i].to().node_id();
				auto test2 = path_[0]->node_id();
				if(this->node()[i].to().node_id() == path_[0]->node_id())
				{
					this->node(node()[i].to());
					break;
				}
			}
			
			path_.erase(path_.begin());
			t_passed_ = from_seconds(0);
		}
	}
}

void cow::set_path(std::vector<const kmint::map::map_node*> path)
{
	path_ = path;
}
