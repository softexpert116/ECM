//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSWindowController.h>

@class NSButton, NSProgressIndicator, NSTextField;
@protocol DynamicErrorWindowDelegate;

@interface DynamicErrorWindowController : NSWindowController
{
    id <DynamicErrorWindowDelegate> _delegate;
    NSTextField *_message;
    NSTextField *_explanation;
    NSButton *_leftButton;
    NSProgressIndicator *_progressIndicator;
    NSButton *_rightButton;
    NSButton *_helpButton;
    long long _diagnosisCode;
}

@property(nonatomic) long long diagnosisCode; // @synthesize diagnosisCode=_diagnosisCode;
@property(nonatomic) __weak NSButton *helpButton; // @synthesize helpButton=_helpButton;
@property(nonatomic) __weak NSButton *rightButton; // @synthesize rightButton=_rightButton;
@property(nonatomic) __weak NSProgressIndicator *progressIndicator; // @synthesize progressIndicator=_progressIndicator;
@property(nonatomic) __weak NSButton *leftButton; // @synthesize leftButton=_leftButton;
@property(nonatomic) __weak NSTextField *explanation; // @synthesize explanation=_explanation;
@property(nonatomic) __weak NSTextField *message; // @synthesize message=_message;
@property(retain, nonatomic) id <DynamicErrorWindowDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)rightActionSelected:(id)arg1;
- (void)leftActionSelected:(id)arg1;
- (void)errorDiagnosedAs:(long long)arg1;
- (void)updateWindowLayout;
- (void)awakeFromNib;

@end

