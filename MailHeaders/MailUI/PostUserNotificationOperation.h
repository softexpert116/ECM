//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSOperation.h>

@class ECAngleBracketIDHash, MCMessage, NSString;

@interface PostUserNotificationOperation : NSOperation
{
    MCMessage *_message;
    NSString *_identifier;
    NSString *_snippet;
    NSString *_messageID;
    ECAngleBracketIDHash *_messageIDHeaderHash;
}

@property(readonly, copy, nonatomic) ECAngleBracketIDHash *messageIDHeaderHash; // @synthesize messageIDHeaderHash=_messageIDHeaderHash;
@property(readonly, copy, nonatomic) NSString *messageID; // @synthesize messageID=_messageID;
@property(readonly, copy, nonatomic) NSString *snippet; // @synthesize snippet=_snippet;
@property(readonly, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
@property(readonly, nonatomic) MCMessage *message; // @synthesize message=_message;
- (void).cxx_destruct;
- (void)cancel;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (void)main;
- (id)description;
- (id)init;
- (id)initWithMessage:(id)arg1 snippet:(id)arg2;

@end

