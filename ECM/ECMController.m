//
//  ECMController.m
//  ECM
//
//  Created by ujs on 10/22/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "ECMController.h"
#import <objc/objc-runtime.h>
#import "MVMailBundle.h"
#import "CodeInjector.h"

int LoggingLevel = 0;

@implementation ECMController

+ (void)initialize
{
    if(self != [ECMController class])
        return;
    
    Class mvMailBundleClass = NSClassFromString(@"MVMailBundle");
    if(!mvMailBundleClass)
        return;
    
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated"
        class_setSuperclass([self class], mvMailBundleClass);
    #pragma GCC diagnostic pop
    
    [self sharedInstance];
    [[((MVMailBundle *)self) class] registerBundle];
}

//
// -----------------------------------------------------------------------------
+ (instancetype)sharedInstance
{
    static dispatch_once_t onceToken;
    static ECMController *instance;
    dispatch_once(&onceToken, ^{
        instance = [[ECMController alloc] init];
    });
    
    return instance;
}
+ (NSString *) extractEmailAddress: (NSString *)address
{
    NSRange r = [address rangeOfString:@"<" options:NSBackwardsSearch];
    NSString *senderEmail = [address substringFromIndex:r.location + 1];
    r = [senderEmail rangeOfString:@">" options:NSBackwardsSearch];
    return [senderEmail substringToIndex:r.location];
}
+ (BOOL)isElCapitan {
    NSProcessInfo *info = [NSProcessInfo processInfo];
    if(![info respondsToSelector:@selector(isOperatingSystemAtLeastVersion:)])
        return NO;
    
    NSOperatingSystemVersion requiredVersion = {10,11,0};
    return [info isOperatingSystemAtLeastVersion:requiredVersion];
}
+ (void) showAlert: (NSString *)msg
{
    NSAlert *alert = [NSAlert alertWithMessageText:msg defaultButton:@"Ok" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@"Alert pop up displayed"];
    [alert runModal];
}
//
// -----------------------------------------------------------------------------
- (instancetype)init
{
    self = [super init];
    
    if (self) {
        [self initMenu];
        [CodeInjector injectUsingMethodPrefix:@"MPP"];
    }
    
    return self;
}

- (void)openECM {
    
    _windowController = [[ECMWindowController alloc] initWithWindowNibName:@"ECMWindowController"];
    
    [_windowController showWindow:self];
}
- (void)initMenu {
    NSApplication *application = [NSApplication sharedApplication];
    NSMenu *theMenu = application.mainMenu;
    NSMenuItem* subGroup = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
    [theMenu addItem:subGroup];

    NSMenu *subMenu = [[NSMenu alloc] initWithTitle:@"ECM"];

    NSMenuItem *openItem = [[NSMenuItem alloc] initWithTitle:@"Open" action:@selector(openECM) keyEquivalent:@""];
    [openItem setTarget:self];
    [subMenu addItem:openItem];

    NSMenuItem *closeItem = [[NSMenuItem alloc] initWithTitle:@"Close" action:nil keyEquivalent:@""];
    [closeItem setEnabled:YES];
    [subMenu addItem:closeItem];

    [theMenu setSubmenu:subMenu forItem:subGroup];
}



@end
