//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface MCImageJunkMetadata : NSObject
{
    unsigned long long _pixelCount;
    unsigned long long _byteCount;
    BOOL _isAnimated;
    long long _type;
    unsigned long long _frameCount;
    double _density;
    struct CGSize _size;
}

+ (id)lsmMarkerForImageDensityCategory:(long long)arg1;
+ (id)lsmMarkerForImageSizeCategory:(long long)arg1;
+ (id)stringForImageType:(long long)arg1;
@property(nonatomic) BOOL isAnimated; // @synthesize isAnimated=_isAnimated;
@property(nonatomic) double density; // @synthesize density=_density;
@property(nonatomic) unsigned long long frameCount; // @synthesize frameCount=_frameCount;
@property(nonatomic) struct CGSize size; // @synthesize size=_size;
@property(nonatomic) long long type; // @synthesize type=_type;
- (id)description;
@property(readonly, nonatomic) long long densityCategory;
@property(readonly, nonatomic) long long sizeCategory;
@property(nonatomic) unsigned long long pixelCount;
@property(nonatomic) unsigned long long byteCount;
- (void)_computeDensity;
- (id)init;
- (id)initWithImage:(id)arg1 name:(id)arg2 type:(long long)arg3;

@end

