import { UnControlled as CodeMirror } from 'react-codemirror2';
import { useState } from 'react';
import 'codemirror/lib/codemirror.css';
import 'codemirror/theme/monokai.css';
import 'codemirror/mode/clike/clike'; // mode for C/C++/Java-like languages
import { useEffect } from 'react';



const Output = ({ title, codemirrorRef }) => {

    const storedIsOpened = localStorage.getItem(title);
    const [isOpened, setIsOpened] = useState(storedIsOpened ? JSON.parse(storedIsOpened) : false);
        useEffect(() => {
        localStorage.setItem(title, JSON.stringify(isOpened));
    }, [isOpened, title]);
    return (

        <>
            {isOpened && <div className='flex border-l-[1.5px] border-[#2F2F2F] flex-col w-full h-fit'>
                <div className={`flex pl-[6px] flex-row w-full py-1 items-center bg-[#2F2F2F] `}>
                    <svg onClick={() => setIsOpened(prev => !prev)} className='w-4 cursor-pointer h-4 text-gray-200' xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
                        <path strokeLinecap="round" strokeLinejoin="round" d="m19.5 8.25-7.5 7.5-7.5-7.5" />
                    </svg>
                    <h2 className=' text-[13px] text-gray-200 ml-[7px] font-semibold tracking-wide text-left'>{title.toUpperCase()}</h2>
                </div>

                <CodeMirror
                    ref={codemirrorRef}
                    className='w-full mt-2 bg-[#272822] text-white rounded-lg'
                    options={{
                        lineNumbers: true,
                        theme: 'monokai',
                        mode: 'text/x-csrc',
                        readOnly: true,
                    }}
                />
            </div>}


            {!isOpened && <div className='flex flex-col w-fit h-full'>
                <div className={`flex px-[4px] flex-row w-fit h-full py-[6px] justify-center bg-[#2F2F2F] `}>

                    <div className='flex flex-col items-center'>
                        <svg onClick={() => setIsOpened(prev => !prev)} className='w-4 cursor-pointer h-4 text-gray-200' xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
                            <path strokeLinecap="round" strokeLinejoin="round" d="m8.25 4.5 7.5 7.5-7.5 7.5" />
                        </svg>

                        {title.toUpperCase() == "QUADRUPLES" && <svg xmlns="http://www.w3.org/2000/svg" className='w-5 mt-1 h-6 text-gray-300' fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
                            <path strokeLinecap="round" strokeLinejoin="round" d="m6.75 7.5 3 2.25-3 2.25m4.5 0h3m-9 8.25h13.5A2.25 2.25 0 0 0 21 18V6a2.25 2.25 0 0 0-2.25-2.25H5.25A2.25 2.25 0 0 0 3 6v12a2.25 2.25 0 0 0 2.25 2.25Z" />
                        </svg>}

                        {title.toUpperCase() == "ERRORS" &&
                            <svg xmlns="http://www.w3.org/2000/svg" fill="none" className='w-5 mt-1 h-6 text-gray-300' viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor">
                                <path strokeLinecap="round" strokeLinejoin="round" d="M12 9v3.75m9-.75a9 9 0 1 1-18 0 9 9 0 0 1 18 0Zm-9 3.75h.008v.008H12v-.008Z" />
                            </svg>}


                        {title.toUpperCase() == "SYMBOL TABLE" &&
                            <svg xmlns="http://www.w3.org/2000/svg" className='w-[22px] mt-1 h-6 text-gray-300' fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
                                <path strokeLinecap="round" strokeLinejoin="round" d="M14.25 9.75 16.5 12l-2.25 2.25m-4.5 0L7.5 12l2.25-2.25M6 20.25h12A2.25 2.25 0 0 0 20.25 18V6A2.25 2.25 0 0 0 18 3.75H6A2.25 2.25 0 0 0 3.75 6v12A2.25 2.25 0 0 0 6 20.25Z" />
                            </svg>

                        }

                    </div>
                </div>
            </div>}
        </>


    );
}

export default Output;