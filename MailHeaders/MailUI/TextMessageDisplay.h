//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "MessageTextViewDelegate-Protocol.h"

@class MCMessage, MessageTextView, NSAttributedString, NSString, NSWindow;

@interface TextMessageDisplay : NSObject <MessageTextViewDelegate>
{
    BOOL _showControlCharacters;
    MCMessage *_message;
    NSWindow *_singleWindow;
    MessageTextView *_textView;
    NSAttributedString *_rawSourceString;
}

+ (void)_removeDisplayForMessage:(id)arg1;
+ (void)displayRawSourceForMessage:(id)arg1;
@property(nonatomic) BOOL showControlCharacters; // @synthesize showControlCharacters=_showControlCharacters;
@property(copy, nonatomic) NSAttributedString *rawSourceString; // @synthesize rawSourceString=_rawSourceString;
@property(nonatomic) __weak MessageTextView *textView; // @synthesize textView=_textView;
@property(retain, nonatomic) NSWindow *singleWindow; // @synthesize singleWindow=_singleWindow;
@property(retain, nonatomic) MCMessage *message; // @synthesize message=_message;
- (void).cxx_destruct;
- (void)saveAs:(id)arg1;
- (void)toggleShowControlCharacters:(id)arg1;
- (void)showPrintPanel:(id)arg1;
- (void)setTitle:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (void)bringToFront;
- (BOOL)validateMenuItem:(id)arg1;
- (id)messageTextView:(id)arg1 willReturnMenu:(id)arg2 forEvent:(id)arg3;
- (void)_displayRawSource;
- (void)_prepareForMessage:(id)arg1;
- (void)_beginBackgroundLoad;
- (void)dealloc;
- (void)awakeFromNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

