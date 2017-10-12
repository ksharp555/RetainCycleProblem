//Retain Cycle problem
//Objective-C is not like Java. Although OC has ARC, we need to take care of ARC. When to use weak and When to use strong.
//From my experience, when we handle delegate, if the child view retain parent view, there should be one Oject in "weak reference" otherwise it will cause Memory leak.

@class Child;
@interface Parent : NSObject {
    Child *child; // Instance variables are implicitly __strong
}
@end
@interface Child : NSObject {
    Parent *parent;
}
@end

@class Child;
@interface Parent : NSObject {
    Child *child;
}
@end
@interface Child : NSObject {
    __weak Parent *parent;
}
@end