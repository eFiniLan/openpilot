using Cxx = import "./include/c++.capnp";
$Cxx.namespace("cereal");

@0xb526ba661d550a59;

# custom.capnp: a home for empty structs reserved for custom forks
# These structs are guaranteed to remain reserved and empty in mainline
# cereal, so use these if you want custom events in your fork.

# you can rename the struct, but don't change the identifier
struct ChatRequest @0x81c2f05a394cf4af {
  text @0 :Text;
}

struct ChatResponse @0xaedffd8f31e7b55d {
  text @0 :Text;
}

struct ControlRequest @0xf35cc4560bbf6ec2 {
  id @0 :Text;
  name @1 :Text;
  args @2 :Text;
}

struct ControlResponse @0xda96579883444c35 {
  id @0 :Text;
  name @1 :Text;
  result @2 :Text;
}

struct ChatLine @0x80ae746ee2596b11 {
  text @0 :Text;
  role @1 :Role;

  enum Role {
    user @0;
    assistant @1;
    car @2;
  }
}

struct VehicleRequest @0xf98d843bfd7004a3 {
  text @0 :Text;
}

struct CustomReserved7 @0xb86e6369214c01c8 {
}

struct CustomReserved8 @0xf416ec09499d9d19 {
}

struct CustomReserved9 @0xa1680744031fdb2d {
}