
#ifndef _ENDPOINT0_H_
#define _ENDPOINT0_H_

/** Function implementing Endpoint 0 for enumeration, control and configuration 
 *  of USB audio devices. It uses the descriptors defined in ``descriptors_2.h``.
 *  
 *  \param c_ep0_out Chanend connected to the XUD_Manager() out endpoint array
 *  \param c_ep0_in Chanend connected to the XUD_Manager() in endpoint array
 *  \param c_audioCtrl Chanend connected to the decouple thread for control 
 *                     audio (sample rate changes etc.)
 *  \param c_mix_ctl Optional chanend to be connected to the mixer thread if
 *                   present
 *  \param c_clk_ctl Optional chanend to be connected to the clockgen thread if
 *                   present.
 *  \param c_usb_test Optional chanend to be connected to XUD if test modes required.
 */
void Endpoint0( chanend c_ep0_out, chanend c_ep0_in, chanend c_audioCtrl, 
        chanend ?c_mix_ctl,chanend ?c_clk_ctl, chanend ?c_usb_test
#ifdef EP0_THREAD_COMBINED_WITH_SPI
  , chanend c_spi, chanend c_spi_ss
#endif
);

#endif
