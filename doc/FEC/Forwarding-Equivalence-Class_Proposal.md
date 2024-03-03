# SAI Forwarding Equivalence Class (FEC) Object Type

## Overview

The FEC is a level of indirection between the route entry and the next hop.
When using a FEC object by multiple route entries, the FEC can provide us with faster convergence to change the next hop of these routes compared with individually changing each route's next hop.

## Usage Example

```c
    // 1. Creating a FEC object
    fec_attrs[0].id = SAI_FEC_ATTR_NEXT_HOP_ID;​
    fec_attrs[0].value = next_hop_1;​
    saistatus = sai_fec_api->create_fec(&fec, switch_id, 1, fec_attrs);​
    // 2. Create a route entry using the new FEC object​
    route_entry.switch_id = 0;​
    route_entry.vr_id = overlay_vrf;​
    route_entry.destination.addr_family = SAI_IP_ADDR_FAMILY_IPV4;​
    route_entry.destination.addr.ip4 = "10.0.0.0";
    route_entry.destination.addr.mask = "255.0.0.0";​
    route_entry_attrs[0].id = SAI_ROUTE_ENTRY_ATTR_NEXT_HOP_ID;​
    route_entry_attrs[0].value.oid = fec;​
    saistatus = sai_route_api->create_route(&route_entry, 1, route_entry_attrs);​
    // More routes can later be assigned to that FEC object​
    // 3. Using FEC for switchover​
    // 3.1. Switchover to another next hop
    fec_attr.id = SAI_FEC_ATTR_NEXT_HOP_ID;​
    fec_attr.value = next_hop_2;​
    saistatus = sai_fec_api->set_fec_attribute(fec, fec_attr);​
    // 3.2. Switchover to a next hop group
    fec_attr.id = SAI_FEC_ATTR_NEXT_HOP_ID;​
    fec_attr.value = next_hop_group_1;​
    saistatus = sai_fec_api->set_fec_attribute(fec, fec_attr);​
```