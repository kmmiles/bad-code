use std::alloc::System;

#[global_allocator]
static A: System = System;

fn main() {
    println!("Hello World!");
}
