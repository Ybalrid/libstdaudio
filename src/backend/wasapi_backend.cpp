
#ifdef LIBSTDAUDIO_BACKEND_WASAPI

//win32
#define NOMINMAX
#include <windows.h>
//IMMDevice
#include <mmdeviceapi.h>
#include <CommCtrl.h>
#include <endpointvolume.h>
#include <Audioclient.h> //WASAPI


//Windows includes needs to be done before this one. 
//Because there's confusion between Windows SDK's "byte" and std::byte, apparently.
#include <__audio_device_list>
#include "../device_impl.h"


_LIBSTDAUDIO_NAMESPACE_BEGIN
//TODO a device must be a wrapper around an IMMDevice 


class immdevice_wasapi_device_impl final : public device_impl
{

};

device get_input_device() {
	return {};
}

device get_output_device() {
	return {};
}

device get_default_input_device()
{
	return {};
}

device get_default_output_device()
{
	return {};
}

device_list& get_input_device_list() {
	static device_list in_devices{ device_list::_underlying_container{} };
	return in_devices;
}

device_list& get_output_device_list() {
	static device_list out_devices{ device_list::_underlying_container{} };
	return out_devices;
}
//TODO is this thing necessary?
//int buffer_list::num_input_buffers() const noexcept {
//  return 0;
//}
//
//int buffer_list::num_output_buffers() const noexcept {
//  return 0;
//}

_LIBSTDAUDIO_NAMESPACE_END
#endif // LIBSTDAUDIO_BACKEND_NONE