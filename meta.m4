  header(network.h)
  init(network_init)
 header(core/periodic.h)
 init(periodic_init)
  header(core/vfs/vfs.h)
  block(Miscelleanous)
  ecmd_feature(d, "d ", ADDR, Dump the memory at ADDR (16 bytes).)
  ecmd_feature(fuse, "fuse",,Display current fuse settings)
  ecmd_feature(hostname, "hostname",,Display hostname.)
  block(Resetting the controller)
  ecmd_feature(reset, "reset",,Reset the Ethersex.)
  ecmd_ifndef(TEENSY_SUPPORT)
    ecmd_feature(wdreset, "wdreset",,Go into endless loop to trigger a watchdog timeout.)
  ecmd_endif()
  header(hardware/ethernet/enc28j60.h)
  ifdef(`conf_IPV6', `ifdef(`conf_IPV6_STATIC', `', `timer(50, `ethernet_config_periodic()')')')
  header(hardware/ethernet/enc28j60.h)
  net_init(init_enc28j60)
  mainloop(network_process)
  timer(50, enc28j60_periodic())
  header(protocols/uip/uip.h)
  header(protocols/uip/uip_router.h)
  ifdef(`conf_TCP', `timer(10, `uip_tcp_timer()')')
  ifdef(`conf_UDP', `timer(10, `uip_udp_timer()')')
  header(protocols/uip/uip_arp.h)
  ifdef(`conf_BOOTLOADER', `', `ifdef(`conf_TEENSY', `', `timer(500, `uip_arp_timer()')')')
  header(protocols/ecmd/via_tcp/ecmd_net.h)
  net_init(ecmd_net_init)

  state_header(protocols/ecmd/via_tcp/ecmd_state.h)
  state_tcp(struct ecmd_connection_state_t ecmd)
  header(services/httpd/httpd.h)
  net_init(httpd_init)

  state_header(services/httpd/httpd_state.h)
  state_tcp(struct httpd_connection_state_t httpd)
  ecmd_feature(io, "io")
  block(Network configuration)
  ecmd_feature(mac, "mac",[xx:xx:xx:xx:xx:xx],Display/Set the MAC address.)
  ecmd_ifdef(DEBUG_ENC28J60)
    ecmd_feature(enc_dump, "enc dump", , Dump the internal state of the enc to serial)
  ecmd_endif()
    
  block(Network configuration)
  ecmd_ifndef(TEENSY_SUPPORT)
    ecmd_ifdef(UIP_SUPPORT)
      ecmd_ifndef(IPV6_SUPPORT)
	ecmd_feature(netmask, "netmask",[IP],Display/Set the network mask.)
      ecmd_endif()

      ecmd_feature(ip, "ip",[IP],Display/Set the IP address.)
      ecmd_feature(gw, "gw",[IP],Display/Set the address of the default router.)
    ecmd_endif()
  ecmd_endif()
