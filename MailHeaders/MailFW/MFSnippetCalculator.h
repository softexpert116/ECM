//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class MFQuoteParser, NSMutableArray, NSOperationQueue;
@protocol MFSnippetCalculatorDelegate;

@interface MFSnippetCalculator : NSObject
{
    NSMutableArray *_messagesToCalculate;
    BOOL _isCalculating;
    id <MFSnippetCalculatorDelegate> _delegate;
    MFQuoteParser *_quoteParser;
    NSOperationQueue *_calculationQueue;
}

+ (id)localizeSnippet:(id)arg1;
@property(readonly, nonatomic) NSOperationQueue *calculationQueue; // @synthesize calculationQueue=_calculationQueue;
@property(readonly, nonatomic) MFQuoteParser *quoteParser; // @synthesize quoteParser=_quoteParser;
@property __weak id <MFSnippetCalculatorDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (id)_snippetFromAttachments:(id)arg1;
- (id)_snippetForMessage:(id)arg1;
- (void)_performSnippetCalculation;
- (void)_queueCalculationIfNecessary;
- (void)calculateSnippetsForMessages:(id)arg1;
- (id)immediatelyCalculateSnippetForMessage:(id)arg1;
- (id)init;

@end

